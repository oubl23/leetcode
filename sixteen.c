#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int threeSumCloest(int* nums, int numSize, int target){
   int i, j, k;
   qsort(nums, numSize, sizeof(int), compare);
   int cloest = *nums + *(nums + 1) + *(nums+2) - target;
   for(i = 0 ; i < numSize - 2; i++){
        int left = i + 1;
        int right  = numSize - 1; 
        while(left < right){
            int res = nums[i] + nums[left] + nums[right] - target;
            printf("%d %d \n", res, cloest);
            if(abs(res) < abs(cloest)){
                cloest = res;
            }
            if( res < 0 ) left++;
            else right--;
        }
   }
   return cloest + target;
}
int main(){
    int arr[] = {0, 2, 1, -3};
    int res;
    res = threeSumCloest(arr, 4, 1);
    printf("%d\n",res);
    return 0;
}
