//
//  main.cpp
//  排序
//
//  Created by 王天亮 on 2020/9/23.
//

#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
int a[11], book[11], number[11], input[10];
int n, num;

void sorts() {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = input[i];
        while(j >= 0 && temp < input[j]) {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = temp;
    }
    int j = 1;
    int i = 0;
    while(i < n - 1) {
//        if (input[i] != input[i + 1]) {
            a[j++] = input[i];
//        }
        i++;
    }
        a[j++] = input[i];
    num = j - 1;
}
void dfs(int step) {
    if (step == num + 1) {
        for (int i = 1 ; i <= num; i++) {
            printf("%d ", number[i]);
        }
        printf("\n");
        return;
    }
    int last = -1;
    for (int i = 1 ; i <= num; i++) {
        if (book[i] == 0 && a[i] != last) {
            number[step] = a[i];
            book[i] = 1;
            last = a[i];
            dfs(step + 1);
            book[i] = 0;
        }
    }
    return;
}
int main(void) {
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sorts();
    dfs(1);
}

//typedef long long ll;
//ll qucik(ll a, ll n) {
//    if (n == 0) {
//        return 1;
//    }else if (n % 2 == 1) {
//        return  qucik(a, n - 1) * a;
//    } else {
//        ll temp = qucik(a, n / 2);
//        return temp * temp;
//    }
//}
//int main(void) {
//    ll a = 0, n = 0;
//    cin >> a >> n;
//    printf("%lld", qucik(a, n));
//}
//int main(void) {
//    int a[100] = {0}, n = 0;
//    cin  >>n;
//    for (int i = 0 ; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0 ; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (a[i] != a[j]) {
//                for (int k = 0; k < n; k++) {
//                    if (k == i) {
//                        printf("%d ", a[j]);
//                    } else if (k == j) {
//                        printf("%d ", a[i]);
//                    } else {
//                        printf("%d ", a[k]);
//                    }
//                }
//                printf("\n");
//            }
//        }
//    }
//}
