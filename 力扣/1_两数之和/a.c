// 哈希表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
};
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int hashSize = numsSize * 2;
    struct HashNode **hashTable = (struct HashNode **)calloc(hashSize, sizeof(struct HashNode *));
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int hashIndex = (complement % hashSize + hashSize) % hashSize;
        struct HashNode *current;
        for (current = hashTable[hashIndex]; current != NULL; current = current->next)
        {
            if (current->key == complement)
            {
                result[0] = current->value;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
        }
        int currentHashIndex = (nums[i] % hashSize + hashSize) % hashSize;
        struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = hashTable[currentHashIndex];
        hashTable[currentHashIndex] = newNode;
    }
    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    if (result != NULL)
    {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    }
    else
    {
        printf("No two sum solution found.\n");
    }
    return 0;
}
