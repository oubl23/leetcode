#include "../leetcode.h"

int removeElement(int* nums, int numsSize, int val){
    int i,index = 0;

    for( i = 0; i < numsSize; i++){
        if(nums[i] != val){
            printf("%d , %d\n",index,nums[i]);
            nums[index++] = nums[i];
        }
    }
    return index;
}

int main(){
    int nums[] = {0,1,2,2,3,0,4,2};
    int i, x = removeElement(nums, 8, 2);
    for(i = 0; i < x; i++){
        printf("%d\t",nums[i]);
    }
    printf("\n");
}
