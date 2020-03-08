//
//  main.c
//  素数环
//
//  Created by 王天亮 on 2020/3/8.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
int fun1(int n) {
    int b = n;
    for (int j = 2; j <= n / 2; j++) {
        if (b % j == 0) {
            return 0;
        }
    }
    return 1;
}
int a[100] = {0}, book[17] = {0}, n = 0;
void dfs(int step) {
    if (step == n) {
        if (fun1(a[n] + a[1])) {
            for (int i = 1; i < n; i++) {
                if (i < n - 1) {
                    printf("%d ", a[i]);
                } else {
                    printf("%d\n", a[i]);
                }
            }
        }
        return ;
    }
    for (int i = 2; i <= n; i++) {
        if (book[i] == 0 && fun1(i + a[step - 1])) {
            a[step] = i;
            book[i]++;
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return ;
}
int main(int argc, const char * argv[]) {
    a[1] = 1;
    book[1] = 1;
    while(scanf("%d", &n)!=EOF) {
    dfs(2);
    }
    return 0;
}
