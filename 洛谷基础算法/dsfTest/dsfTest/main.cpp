//
//  main.cpp
//  dsfTest
//
//  Created by 王天亮 on 2020/10/15.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//vector<vector<int> >a(50, vector<int>(50));
////vector<int> book(20, 0);
////vector<int> num(50, 0);
//vector<vector<int> >book(50, vector<int>(50));
//int endx, endy;
//struct num {
//    int x;
//    int y;
//} nums[50];
//
////int number;
////vector<int> num(20, 0);
////void dfs(int step) {
////    if (step > number) {
////        for (int i = 1; i <= number; i++) {
////            printf("%d ", num[i]);
////        }
////        printf("\n");
////        return;
////    }
////    for (int i = 1; i <= number; i++) {
////        if (book[i] == 0) {
////            num[step] = i;
////            book[i] = 1;
////            dfs(step + 1);
////            book[i] = 0;
////        }
////    }
////    return;
////}
//int n = 0;
//int minNumber = INT_MAX;
//int nextXY[4][2] = {
//    {0, 1},
//    {1, 0},
//    {0, -1},
//    {-1, 0}
//};
//void dfs(int x, int y, int step) {
//    if (x == endx && y == endy) {
//        if (minNumber > step) {
//            minNumber = step;
//            for (int i = 1; i < minNumber; i++) {
//                printf("%d %d\n", nums[i].x, nums[i].y);
//            }
//        }
//        return;
//    }
//    int tx = 0, ty = 0;
//    for (int i = 0; i < 4; i++) {
//        tx = x + nextXY[i][0];
//        ty = y + nextXY[i][1];
//        if (tx < 1 || tx > n || ty < 1 || ty > n) {
//            continue;
//        }
//        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
//            nums[step].x = tx;
//            nums[step].y = ty;
//            book[tx][ty] = 1;
//            dfs(tx, ty, step + 1);
//            book[tx][ty] = 0;
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    cin >>n;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> a[i][j];
//        }
//    }
//    cin >> endx;
//    cin >> endy;
////    cin >> number;
//    dfs(1, 1, 1);
//    printf("%d\n", minNumber);
//    return 0;
//}
vector<vector<int> > a(50, vector<int>(50, 0));
vector<vector<int> > book(50, vector<int>(50, 0));
int nextNumber[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
int minNumer = INT_MAX;
int endX = 0, endY = 0;
int n = 0;
void dfs(int x, int y, int step) {
    if (x == endX && y == endY) {
        if (step < minNumer) {
            minNumer = step;
        }
        return ;
    }
    int tx = 0, ty = 0;
    for (int i = 0; i < 4; i++) {
        tx = x + nextNumber[i][0];
        ty = y + nextNumber[i][1];
        if (tx < 1 || tx > n || ty < 1 || ty > n) {
            continue;
        }
        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}
int com(int a, int b) {
    if (a > b) {
        return 1;
    }
    return 0;
}
#include <algorithm>
int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> a[i][j];
//        }
//    }
//    cin >> endX >> endY;
//    dfs(1, 1, 0);
//    printf("%d", minNumer);
    stack <int >sta;
    sta.top()
    cin >>n;
    for (int i = 0 ; i < n; i++) {
        int temp;
        cin >>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end(), com);
    for (int i = 0 ; i < n; i++) {
        printf("%d", nums[i]);
    }
}
