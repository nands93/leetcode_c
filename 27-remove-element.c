//https://leetcode.com/problems/remove-element/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0)
        return 0;
    int temp = 0;
    int len = numsSize - 1;
    while (temp <= len) {
        if (nums[temp] == val) {
            nums[temp] = nums[len];
            len--;
        }
        else
            temp++;
    }
    return temp;
}

int main() 
{
    int nums[] = {3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("numsSize: %d\n", numsSize);
    int val = 5;

    int newLength = removeElement(nums, numsSize, val);
    
    printf("\nNew length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}