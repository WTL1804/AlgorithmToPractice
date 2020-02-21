//
//  main.m
//  最长公共前缀
//
//  Created by 王天亮 on 2020/2/21.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import <Foundation/Foundation.h>

char * longestCommonPrefix(char ** strs, int strsSize) {
    int n = 999;
    if (strsSize == 0) {
        return "";
    }
   for (int i = 0; i < strsSize; i++) {
       if (strlen(strs[i]) < n) {
           n = strlen(strs[i]);
       }
   }
   
    char s[10000] = {0};
    int flag = 0, flag2 = 0;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < strsSize - 1; j++) {
            if (strs[j][i] != strs[j + 1][i]) {
                flag++;
                break;
            }
        }
        if (flag != 0) {
            break;
        }
        s[flag2++] = strs[0][i];
    }
    for (int i = 0; i < flag2; i++) {
        printf("%c", s[i]);
    }
   char *S = s;
    return S;
    
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
