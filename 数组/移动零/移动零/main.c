//
//  main.c
//  移动零
//
//  Created by 王天亮 on 2020/2/13.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
void moveZeroes(int* nums, int numsSize){
    if (numsSize == 1) {
        return ;
    }
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i; j < numsSize - i - 1; j++) {
            if (nums[j] == 0) {
                nums[j] = nums[j + 1];
                nums[j + 1] = 0;
            }
        }
    }
    if (nums[0] == 0) {
        nums[0] = nums[1];
        nums[1] = 0;
    }
}
