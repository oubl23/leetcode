#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int** twoSum(int* nums, int low, int high,  int target, int before, int** results, int* count){
    while(low < high){
        int diff = target - before - nums[low];
        if(diff > nums[high]){
            while(++low < high && nums[low] == nums[low - 1]){}
        } else if(diff < nums[high]){
            while(--high > low && nums[high] == nums[high + 1]){}
        } else{
            results[*count] = malloc(3 * sizeof(int));
            results[*count][0] = before;
            results[*count][1] = nums[low];
            results[*count][2] = nums[high];
            (*count)++;
            while (++low < high && nums[low] == nums[low - 1]) {}
            while (--high > low && nums[high] == nums[high + 1]) {}
        }
    }
}
int** threeSum(int* nums, int numSize, int target, int* returnSize){
    if(numSize < 3){
        return NULL;
    }

    qsort(nums, numSize, sizeof(int), compare);
    *returnSize = 0;
    int i,j,capacity = 50000;
    int **results = malloc(capacity * sizeof(int *));
    for(i=0; i < numSize ; i++){
        if(i == 0 || i > 0 && nums[i] != nums[i - 1]){
            twoSum(nums, i+1, numSize -1, target ,nums[i], results, returnSize);
        }
    }
    return results;
}
static void k_sum(int* nums, int low, int high, int target, int total, int k, int* stack, int len, int** results, int* count){
    int i;
    if(k == 2){
        while(low < high){
            int diff = target - nums[low];
            if( diff > nums[high]) {
                while(++low < high && nums[low] == nums[low - 1] ){}
            } else if(diff < nums[high]){
                while(--high > low && nums[high] == nums[high + 1]){}
            }else{
                stack[len++] = nums[low];
                stack[len++] = nums[high];
                results[*count] = malloc(total * sizeof(int));
                memcpy(results[*count], stack, total * sizeof(int));
                (*count)++;
                len -= 2;
                while (++low < high && nums[low] == nums[low - 1]) {}
                while (--high > low && nums[high] == nums[high + 1]) {}
            }
        }
    }else{
        for(i = low; i <= high - k + 1; i++){
            if( i > low && nums[i] == nums[i-1]) continue;
            stack[len++] = nums[i];
            k_sum(nums, i+1, high, target - nums[i], 4, k -1, stack, len, results,count);
            len--;
        }
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize){
    if(numsSize < 4){
        return NULL;
    }
    qsort(nums,numsSize, sizeof(*nums),compare);
    *returnSize = 0;
    int i, j , capacity = 50000;
    int **results = malloc(capacity * sizeof(int *));
    int *stack = malloc(4*sizeof(int));
    k_sum(nums, 0, numsSize - 1, target, 4, 4, stack, 0, results, returnSize);
    return results;
}
int main(){
    int count;
    int arr[] = {1,2,3,4,0};
    int** res = fourSum(arr,5,6,&count);
    int i;
    printf("%d\n",count);
    for(i = 0; i < count; i++){
       printf("[%d, %d, %d, %d]\n",res[i][0],res[i][1],res[i][2],res[i][3]);
    }
}
