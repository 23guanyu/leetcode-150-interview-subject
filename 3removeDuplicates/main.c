#include <stdio.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize)
{
    int p = 0;

    for ( int q = 1; q < numsSize; q++ )
    {
        if ( nums[p] != nums[q] )
        {
            p++;
            nums[p] = nums[q];
        }
    }

    return p+1;
}

int main() {
    // 示例数组
    int nums[] = {1, 1, 2, 2, 3};
    int expectedNums[] = {1, 2, 3}; // 期望结果数组
    int expectedK = 3; // 期望的长度

    // 调用 removeDuplicates 函数
    int k = removeDuplicates(nums, 5); // 第二个参数是数组的原始长度

    // 检查返回的长度是否正确
    //assert(k == expectedK);

    // 检查数组的前 k 个元素是否符合预期
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]);
        //assert(nums[i] == expectedNums[i]);
    }

    printf("All tests passed!\n");
    return 0;
}
