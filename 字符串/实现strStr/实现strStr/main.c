//
//  main.c
//  实现strStr
//
//  Created by 王天亮 on 2020/2/19.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
//最后一个样例超时，需要用kmp算法。

int strStr(char * haystack, char * needle) {
    if (strlen(needle) == 0) {
        return 0;
    }
    int j = 0, flag = 0, q = 0;;
    for (int i = 0; i < strlen(haystack); i++) {
        if (haystack[i] == needle[j]) {
            printf("%d\n", i);
            int p = i;
            q = i;
            flag = 0;
            for (int k = 0; k < strlen(needle); k++) {
                if (haystack[p] != needle[k]) {
                    flag++;
                    printf("&%d\n", k);
                    break;
                }
                p++;
                if (p == strlen(haystack) && k != strlen(needle) - 1) {
                    flag++;
                     printf("*%d\n", k);
                    break;
                }
            }
            if (flag == 0) {
                return q;
            }
        }
    }
    return -1;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
