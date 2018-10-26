#include <stdio.h>
#include <stdlib.h>
//三数之和
static int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}
int two_sum(int *nums, int low, int high, int target)
{
    int result = nums[low] + nums[high];
    while (low < high) {
        int diff = target - nums[low];
        if(abs(result - target)>abs(nums[low] + nums[high] - target)) {
            result = nums[low] + nums[high];
        }
        if (diff > nums[high]) {
            while (++low < high && nums[low] == nums[low - 1]) {}
        } else if (diff < nums[high]) {
            while (--high > low && nums[high] == nums[high + 1]) {}
        } else {
            break;
        }
    }
    return result;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (numsSize < 3) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(*nums), compare);
    int i, j, capacity = 50000;
    int result = nums[0]+nums[1]+nums[2];
    for (i = 0; i < numsSize-2; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1] )) {
            int res = two_sum(nums, i + 1, numsSize - 1, target-nums[i]);
            if(abs(result - target) > abs( nums[i] + res - target )) {
                result = nums[i] + res;
            }
        }
    }
    return result;
}

int main(){
    int arr[] ={1,2,3,4};
    int res = threeSumClosest(arr, 4, 3);
    printf("%d\n", res);
    return 0;
}
