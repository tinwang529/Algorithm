#include <stdio.h>
/*
倒叙双指针
时间复杂度：O(m + n)，其中 m 和 n 分别是 nums1 和 nums2 的长度。我们最多需要遍历两个数组一次。
空间复杂度：O(1)，我们只使用了常数级别的额外空间来存储指针和临时变量。
*/
void merge(int *nums1, int m, int *nums2, int n)
{
    int i = m - 1;     // nums1的最后一个元素索引
    int j = n - 1;     // nums2的最后一个元素索引
    int k = m + n - 1; // 合并后数组的最后一个元素索引

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // 如果nums2还有剩余元素，直接复制到nums1前面
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
int main()
{
    int nums1[6] = {1, 2, 3, 0, 0, 0}; // nums1有足够的空间来存储合并后的结果
    int nums2[3] = {2, 5, 6};
    int m = 3; // nums1中有效元素的数量
    int n = 3; // nums2中元素的数量

    merge(nums1, m, nums2, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}