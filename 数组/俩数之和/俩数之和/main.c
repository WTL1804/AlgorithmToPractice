//
//  main.c
//  俩数之和
//
//  Created by 王天亮 on 2020/2/13.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = (int *)malloc(sizeof(int) *2);
    int i = 0, j = numsSize - 1;
    if (numsSize == 1 && nums[0] == target) {
        a[0] = target;
        *returnSize = 1;
        return a;
    }
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                i = numsSize;
                break;
            }
        }
    }
    return a;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
