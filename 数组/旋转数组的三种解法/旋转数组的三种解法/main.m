//
//  main.m
//  旋转数组的三种解法
//
//  Created by 王天亮 on 2020/2/16.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import <Foundation/Foundation.h>
void rotate(int* nums, int numsSize, int k){
int previous, temp;
for (int i = 0; i < k; i++) {
        previous = nums[numsSize - 1];
        for (int j = 0; j < numsSize; j++) {
            temp = nums[j];
            nums[j] = previous;
            previous = temp;
        }
    }
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
