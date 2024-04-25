#include "stdio.h"
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int valNum = 0;
    for ( int i = 0; i < numsSize; i++ )
    {
        if ( nums[i] == val )
        {
            valNum++;
        }
    }

    for ( int i = 0; i < numsSize; i++ )
    {
        if ( nums[i] == val )
        {
            for ( int j = i+1; j < numsSize; j++ )
            {
                if ( nums[j] != val )
                {
                    nums[i] = nums[j];
                    nums[j] = val;
                    break;
                }
            }
        }
    }
    return numsSize - valNum; 
}

int main() {
    int nums[] = {3, 2, 2, 3, 4, 5, 6}; // 示例数组
    int val = 3;               // 需要移除的值
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeElement(nums, numsSize, val);

    printf("New array length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}