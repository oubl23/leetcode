#include "../leetcode.h"
// 0 1 2 3 4 5 6 7
// 1 2 3 4 5 6 7 0
// 2 3 4 5 6 7 0 1
// 3 4 5 6 7 0 1 2 
// 4 5 6 7 0 1 2 3
// 5 6 7 0 1 2 3 4
// 6 7 0 1 2 3 4 5
// 7 0 1 2 3 4 5 6

int searchHelp(int* nums, int x,int y, int target){
    int mid = (x + y )  / 2;
    printf("x = %d ,y = %d ,mid = %d\n",x,y,mid);
    if( x > y || x < 0){
        return -1;
    }
    if(y - x == 1){
        if(nums[x] == target)
            return x;
        else if(nums[y] == target)
            return y;
        else 
            return -1;
    }
    if( x == y && nums[x] != target ) {
        return -1;
    }
    if( nums[mid] == target){
        return mid;
    }else{
        if( nums[mid] < nums[y] ){
            if(target > nums[mid] && target <= nums[y]){
                return searchHelp(nums,mid + 1, y, target);
            }else{
                return searchHelp(nums,x, mid - 1, target);
            }
        } else {
            if(target < nums[mid] && target >= nums[x]){
                return searchHelp(nums,x , mid - 1, target);
            }else{
                return searchHelp(nums,mid + 1, y, target);
            }

        }
    }
}

int search(int* nums,int numsSize, int target){
    return searchHelp(nums, 0, numsSize -1, target);
}
int searchOther(int* nums, int numsSize, int target){
    if( numsSize == 0 ){
        return -1;
    }
    int start = 0;
    int end = numsSize - 1;
    while( start <= end){
        int mid = start + (end - start) /2;
        if(nums[mid] == target){
            return mid;
        }
        if( nums[mid] >= nums[start]){
            if( target >= nums[start] && target < nums[mid] ){
                end = mid -1;
            }else {
                start = mid + 1;
            }
        }
        if( nums[mid] <= nums[end]){
            if ( target > nums[mid] && target <= nums[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
}

int main(){
    int a[] = {1,3,5};
    int x = search(a, 3, 5);
    printf("%d\n", x);
}
