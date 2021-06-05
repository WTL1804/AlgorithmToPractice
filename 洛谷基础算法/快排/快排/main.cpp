//
//  main.cpp
//  快排
//
//  Created by 王天亮 on 2020/10/28.
//

#include <iostream>
#include <vector>
using namespace std;
//void quickSort(vector<int > &num, int left, int right) {
//    if (left > right) {
//        return ;
//    }
//    int i = left, j = right;
//    int temp = num[left];
//    while(i != j) {
//        while(i < j && num[j] >= temp) {
//            j--;
//        }
//        while(i < j && num[i] <= temp) {
//            i++;
//        }
//        if (i < j) {
//            int temps = num[i];
//            num[i] = num[j];
//            num[j] = temps;
//        }
//    }
//    num[left] = num[i];
//    num[i] = temp;
//    quickSort(num, left, i - 1);
//    quickSort(num, i + 1, right);
//
//}
//int main(int argc, const char * argv[]) {
//    vector<int> a(5, 0);
//    for (int i = 0; i < 5; i++) {
//        cin>>a[i];
//    }
//    quickSort(a, 0, 4);
//    for (int i = 0; i < 5; i++) {
//        printf("%d ",a[i]);
//    }
//}



//第k个大的数。
int k = 7;
void quickSort(vector<int > &num, int left, int right) {
    if (left > right) {
        return ;
    }
    int i = left, j = right;
    int temp = num[left];
    while(i < j) {
        while(i != j && temp <= num[j]) {
            j--;
        }
        while(i != j && temp >= num[i]) {
            i++;
        }
        if (i < j) {
            int temps = num[i];
            num[i] = num[j];
            num[j] = temps;
        }
    }
    num[left] = num[i];
    num[i] = temp;
    if (i == k - 1) {
        printf("%d", num[i]);
    } else if (i < k - 1) {
        quickSort(num, i + 1, right);
    } else {
        quickSort(num, left, i - 1);
    }
//    quickSort(num, left, i - 1);
//    quickSort(num, i + 1, right);
}
//int main(void) {
//    vector<int> a(10, 0);
//    for (int i = 0; i < 10; i++) {
//        cin >> a[i];
//    }
//    cin >> k;
//    quickSort(a, 0, 9);
////    for (int i = 0; i < 5; i++) {
////        printf("%d ",a[i]);
////    }
//}

void quickSorts(vector<int> &a, int left, int right) {
    if (left > right) {
        return ;
    }
    int i = left, j = right, temp = a[left];
    while(i < j) {
        while(a[j] >= temp && i != j) {
            j--;
        }
        while (a[i] <= temp && i != j) {
            i++;
        }
        if (i != j) {
            int number = a[i];
            a[i] = a[j];
            a[j] = number;
        }
    }
    a[left] = a[i];
    a[i] = temp;
    quickSorts(a, left, j - 1);
    quickSorts(a, j + 1, right);
}

int main(int argc, const char * argv[]) {
    vector<int> a(5, 0);
    for (int i = 0; i < 10; i++) {
        cin>>a[i];
    }
    quickSort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ",a[i]);
    }
}


