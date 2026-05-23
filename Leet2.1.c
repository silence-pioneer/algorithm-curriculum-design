#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int majorityElement(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    int a = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) a = nums[i];
        if (a == nums[i]) count++;
        else count--;
    }
    return a;
}
int main() {
    int nums[] = {2, 2, 1, 1, 1, 2, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", majorityElement(nums, size));
    return 0;
}