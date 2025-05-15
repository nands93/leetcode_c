#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int unique = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[unique] = nums[i];
            unique++;
        }
    }
    return unique;
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int uniqueCount = removeDuplicates(nums, numsSize);
    
    printf("Number of unique elements: %d\n", uniqueCount);
    printf("Modified array: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}