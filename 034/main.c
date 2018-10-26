#include "../leetcode.h"

int* searchRangeError(int* nums, int numsSize, int target, int* returnSize){
    int start = -1;
    int end = -1;
    int i,j;
    i = 0; 
    j = numsSize - 1;
    int mid ;
    
    while( i <= j){
        mid = (i + j) / 2;
        if( nums[mid] == target){
            break;
        }else if(nums[mid] > target){
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }
    if( i > j){
        start = -1;
        end = -1;
    }else{

        i = mid;
        int x , y;
        x = 0;
        while(mid > 0 && x < mid &&  nums[mid - 1] == nums[mid]){
            y = ( x + mid ) / 2;
            if( nums[y] != target){
                x = y + 1;
            }else{
                mid = y;
            }
        }
        start  =  mid;
        x = numsSize - 1;
        while(i < (numsSize -1) && x > i && nums[i + 1] == nums[i]) {
            y = (x + i ) /2;
            if( nums[y] != target){
                x = y - 1;
            }else{
                i = y;
            }
        }
        end = i;
    }
    int* result = malloc(2 * sizeof(int));
    result[0] = start;
    result[1] = end;
    *returnSize = 2;
    return result;
}

static int binary_search_start(int *a, int size, int target){
    int low = -1;
    int high = size;
    while(low + 1 < high){
        int mid = low + (high - low) / 2;
        if( target > a[mid] ){
            low = mid;
        }else{
            high = mid;
        }
    }

    if(high == size || a[high] != target){
        return -1;
    }else{
        return high;
    }
}

static int binary_search_end(int *a, int size, int target){
    int low = -1;
    int high = size;
    while(low + 1 < high) {
        int mid = low + (high - low) / 2;
        if( target < a[mid]){
            high = mid;
        }else{
            low = mid;
        }
    }
    if(low == -1 || a[low] != target){
        return -1;
    }else{
        return low;
    }
}

static int* searchRange(int* nums, int numsSize, int target,int* returnSize){
    int *range = malloc(2* sizeof(int));
    *returnSize = 2;
    if(numsSize == 0){
        range[0] = range[1] = -1;
        return range;
    }

    range[0] = binary_search_start(nums,numsSize,target);
    range[1] = binary_search_end(nums,numsSize,target);
    return range;
}

int main(){
    int nums[] = {5,7,7,8,8,10};
    int size ;
    int* a = searchRange(nums, 6, 7, &size);
    int i = 0;
    for(; i < size; i++){
        printf("%d\t", a[i]);
    }
}
