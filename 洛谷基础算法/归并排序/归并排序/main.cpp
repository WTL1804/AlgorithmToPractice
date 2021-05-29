//
//  main.cpp
//  归并排序
//
//  Created by 王天亮 on 2020/10/28.
//

#include <iostream>
#include <vector>
using namespace std;
//vector<int>mergeSort(vector<int>left, vector<int>right) {
//    vector<int >result;
//    while(left.size() > 0 && right.size() > 0) {
//        if (left[0] > right[0]) {
//            result.push_back(left[0]);
//            left.erase(left.begin());
//        } else {
//            result.push_back(right[0]);
//            right.erase(right.begin());
//        }
//    }
//    while(left.size() > 0) {
//        result.push_back(left[0]);
//        left.erase(left.begin());
//    }
//    while(right.size() > 0) {
//        result.push_back(right[0]);
//        right.erase(right.begin());
//    }
//    return result;
//}
//vector<int> merg(vector<int>n) {
//    if (n.size() < 2) {
//        return n;
//    }
//    int mid = (int)n.size() / 2;
//    vector<int> left(n.begin(), n.begin() + mid);
//    vector<int> right(n.begin() + mid, n.end());
//    return mergeSort(merg(left), merg(right));
//}

//快速排序
int main(int argc, const char * argv[]) {
    vector<int> n(5, 0);
    for (int i = 0; i < 5; i++) {
        cin >> n[i];
    }
    vector<int> a;
    for (int i = 0; i < 5; i++) {
      printf("%d", a[i]);
    }
}
