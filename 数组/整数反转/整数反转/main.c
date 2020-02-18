//
//  main.c
//  整数反转
//
//  Created by 王天亮 on 2020/2/17.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int reverse(int x){
   int flag = 0;
    if (x < 0) {
        flag++;
        x = -x;
    }
    char s[35] = {0};
    int n = x, k = 0;
    
    while(n) {
        s[k++] = n % 10;
        n = n / 10;
    }
    int sum = 0, j = 1;
    for (int i = k - 1; i >= 0; i--) {
        sum = sum + s[i] *j;
        j = j * 10;
    }
    if (flag != 0) {
        sum = -1*sum;
    }
    if (sum > 2*pow(2,31) - 1) {
        return 0;
    }
    if (sum < -1 *2*pow(2,31)) {
        return 0;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
   printf("%d",reverse(1534236469));
    
    return 0;
}
