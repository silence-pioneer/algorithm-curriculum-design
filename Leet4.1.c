#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool canJump(int* nums, int numsSize) {
    int farthest = 0;
    for(int i = 0; i < numsSize; i++) {
        if(i > farthest)
            return false;
        if(i + nums[i] > farthest)
            farthest = i + nums[i];
        if(farthest >= numsSize - 1)
            return true;
    }
    return true;
}
int main(){
    int nums[] = {3,2,1,0,4};
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("%d",canJump(nums,size));
    return 0;
}