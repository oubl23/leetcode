#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int  compare(const void* a, const void* b){
    return *(int *)a - *(int*)b;
}

static void k_sum(int *nums, int low, int high, int target, int total, int k, int len, int* stack, int** result, int* count){
    int i;
    if( k == 2){
        while(low <  high){
            // printf("low = %d high = %d \n",low, high);
            int diff = target - nums[low];
            if( diff > nums[high]){
                while(++low < high && nums[low] == nums[low - 1]) {}
            }else if(diff < nums[high]){
                while(--high > low && nums[high] == nums[high + 1]) {}
            }else{
                stack[len++] = nums[low];
                stack[len++] = nums[high];
                result[*count] = malloc(total * sizeof(int));
                memcpy(result[*count], stack, total * sizeof(int));
                (*count)++;
                len -= 2;
                while(++low < high && nums[low] == nums[low -1]) {}
                while(--high > low && nums[high] == nums[high + 1]) {}
            }

        }
    }else{
        for(i = low; i <= high - k + 1; i++){
            if(i > low && nums[i] == nums[i-1]) continue;
            stack[len++] = nums[i];
            k_sum(nums, i + 1, high,target -nums[i],4, k - 1, len, stack, result, count);
            len--;
        }
    }
}

int** four_sum(int* nums, int numsSize, int target,  int* resultSize){
    if(numsSize < 4) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    (*resultSize) = 0;
    int** results = malloc(5000 * sizeof(int*));
    int* stack = malloc(4 * sizeof(int));
    k_sum(nums, 0, numsSize -1, target, 4, 4, 0, stack, results, resultSize);
    return results;
}

int main(void){
    int i, count;
    int nums[] = { 0, 1, 5, 0, 1, 5, 5, -4 };
    int **quadruplets = four_sum(nums, sizeof(nums) / sizeof(*nums), 6, &count);
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
        printf("%d %d %d %d\n", quadruplets[i][0], quadruplets[i][1], quadruplets[i][2], quadruplets[i][3]);
    }

    return 0;
}
