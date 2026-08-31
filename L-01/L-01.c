#include<stdio.h>

int* twoSum(int* nums, int numSize, int target, int* returnSize){
    //分配两个int空间存下标
    int* res = (int*)malloc(sizeof(int)*2);
    //规定返回数组长度为2
    *returnSize = 2;

    for(int i = 0; i < numSize; i++){
        for(int j = i + 1; j < numSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }

        }

    }
    return res;


}
int main(void)
{
    int arr[] = {2,7, 11, 15};
    int numSize = sizeof(arr) / sizeof(arr[0]); 
    int returnSize;
    int *result = twoSum(arr, numSize, 18, &returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]); // 利用 returnSize 知道数组长度是2
    }

    free(result);
    return 0;
}