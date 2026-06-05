#include <stdio.h>
int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // 计算中间索引，避免溢出
        if (nums[mid] == target)
        {
            return mid; // 找到目标元素，返回索引
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // 目标元素在右半部分
        }
        else
        {
            right = mid - 1; // 目标元素在左半部分
        }
    }
    return left; // 没有找到目标元素，返回插入位置
}
int main()
{
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = searchInsert(nums, numsSize, target);
    printf("Target %d should be inserted at index: %d\n", target, result);

    return 0;
}