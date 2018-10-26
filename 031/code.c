#include "../leetcode.h"

void swap(int* nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void nextPermutation(int* nums, int numsSize){
    int i = numsSize - 2;
    int j;
    while(i >= 0 && nums[i] >= nums[i+1]){
        i--;
    }
    
    if(i >= 0){
        j = i + 1;
        while(j < numsSize && nums[i] < nums[j]){
            j++;
        }
        swap(nums, i , j - 1);
    }
    
    i++;
    int k = numsSize - 1;
    while( i < k){
        swap(nums, i, k);
        i++;
        k--;
    }
}

int main(){
    int nums[3] = {3,2,1};
    int i;
    for(i = 0; i < 3; i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");

    nextPermutation(nums,i);
    for(i = 0; i < 3; i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");

}
