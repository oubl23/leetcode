#include "../leetcode.h"
void swap(int* nums,int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void nextPermutation(int* nums, int numsSize){
    if(numsSize <= 1){
        return;
    }
    int i = numsSize - 2;
    while(i >=0 && nums[i] >= nums[i + 1]){
       i--; 
    }

    if( i > 0 ) {
        int j = i + 1;
        while(j < numsSize && nums[j] > nums[i]){
            j++;
        }
        swap(nums, i, j - 1);
    }

    int k = numsSize -1;
    i++;
    while(i<k){
        swap(nums,i,k);
        i++;
        k--;
    }
}
