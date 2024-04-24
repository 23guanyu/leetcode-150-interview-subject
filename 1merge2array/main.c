#include "stdio.h"
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int * ptr1 = nums1;
    int * ptr2 = nums2;
    int store[m+n];
    int *dest = store;

    // 用来确保我们不会读取nums1原有数组之后的内容
    int *end1 = nums1 + m;
    // 用来确保我们不会读取nums2数组之后的内容
    int *end2 = nums2 + n;

    while (ptr1 < end1 && ptr2 < end2) {
        if (*ptr1 <= *ptr2) {
            *dest++ = *ptr1++;
        } else {
            *dest++ = *ptr2++;
        }
    }

    while ( ptr1 < end1 )
    {
        *dest++ = *ptr1++;
    }

    while ( ptr2 < end2 )
    {
        *dest++ = *ptr2++;
    }

    for ( int i = 0; i < m + n; i++ )
    {
        nums1[i] = store[i];
    }
    
}

int main() {
    int nums1Size = 6; // nums1的大小必须足够大，能够存储合并后的数组
    int m = 3; // nums1中初始化的元素数量
    int nums2Size = 3;
    int n = 3; // nums2中元素的数量

    int* nums1 = (int*)malloc(nums1Size * sizeof(int));
    int* nums2 = (int*)malloc(nums2Size * sizeof(int));

    // 初始化nums1和nums2
    nums1[0] = 1;
    nums1[1] = 3;
    nums1[2] = 5;

    nums2[0] = 2;
    nums2[1] = 4;
    nums2[2] = 6;

    // 调用merge函数
    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    // 打印合并后的nums1
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // 释放内存
    free(nums1);
    free(nums2);

    return 0;
}
