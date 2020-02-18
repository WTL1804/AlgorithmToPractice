//
//  main.c
//  字符串转换整数
//
//  Created by 王天亮 on 2020/2/18.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
int myAtoi(char * str) {
    int j = -1;
    if (strlen(str) == 0) {
        return 0;
    }
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            continue;
        }
        j = i;
        break;
    }
    if (j == -1) {
        return 0;
    }
    for (int i = j; i < strlen(str); i++) {
        if (str[i] == '0') {
            continue;
        }
        if (i != 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] == '0') {
           return 0;
        }
        j = i;
        break;
    }
    printf("%d", j);
    if (j == 0 && str[0] == '0') {
        return 0;
    }
    if (!(str[j] >= '0' && str[j] <= '9') && str[j] != '-' && str[j] != '+') {
        return 0;
    }
    int k = 1, sum = 0, flag = 0;
    if ( str[j] == '-' || str[j] == '+') {
        if (str[j] == '-') {
            flag = -1;
        }
        j++;
    }
    for (int i = j; i < strlen(str); i++) {
        if (str[i] == '0') {
            continue;
        }
        j = i;
        break;
    }
    int s[1000] = {0};
    int b = 0;
  //y > 214748364 || y < -214748364
    for (j; j < strlen(str); j++) {
        if (!(str[j] >= '0' && str[j] <= '9')) {
            break;
        }
        s[b++] = str[j] - '0';
    }
    if (flag == -1 && b > 10) {
        return -2147483648;
    }
    if (flag != -1 && b > 10) {
        return 2147483647;
    }
    for (int i = b - 1; i >= 0; i--) {
        if (flag == -1) {
            if (k >= 1000000000 && i == 0 && s[b - 1] >= 9) {
                return -2147483648;
             }
            sum = sum - s[i]*k;
            
            if (k >= 1000000000 && i == 0) {
                return sum;
            } else if (k >= 1000000000 && i != 0) {
                return -2147483648;
            }
            k = k * 10;
        } else {
            sum = sum + s[i]*k;
            if (k >= 1000000000 && i == 0) {
                return sum;
            } else if (k >= 1000000000 && i != 0) {
                return 2147483647;
            }
            k = k * 10;
        }
        if (s[0] >= 2 && sum >= 147483647) {
            return 2147483647;
        }
        if (s[0] >= 2 && sum <= -147483648) {
            return -2147483648;
        }
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
