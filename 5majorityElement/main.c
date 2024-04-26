#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}

int main()
{
    int nums[] = {1, 1, 1, 1, 1, 5, 6, 6, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("The majority element is: %d\n", majorityElement(nums, numsSize));
    return 0;
}
