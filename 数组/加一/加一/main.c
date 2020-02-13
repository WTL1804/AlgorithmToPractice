//
//  main.c
//  加一
//
//  Created by 王天亮 on 2020/2/13.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int  i = digitsSize - 1;
    int *a =  (int *)malloc(sizeof(int)*digitsSize+1);
    int flag1 = 0, flag2 = 0;
    if (digits[i] != 9) {
        flag1++;
    }
    while(digits[i] == 9) {
        digits[i] = 0;
        i--;
        if (i < 0) {
            flag2++;
            break;
        }
       if (digits[i] != 9) {
           flag1++;
       }
        
    }
    if (flag1) {
        digits[i]++;
        for (int j = 0; j < digitsSize; j++) {
            a[j] = digits[j];
        }
        *returnSize = digitsSize;
        return a;
    }
    if (flag2) {
        a[0] = 1;
        int j = 0;
        for (j = 0; j < digitsSize; j++) {
            a[j + 1] = digits[j];
        }
        *returnSize = digitsSize + 1;
    }
    return a;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int p[1] ={9};
    int h;
    int *a = plusOne(p, 1, &h);
    for (int i = 0; i < h; i++) {
        printf("%d\n", *a);
        a++;
    }
    return 0;
}
