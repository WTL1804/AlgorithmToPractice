//
//  main.cpp
//  bfsTest
//
//  Created by 王天亮 on 2020/10/15.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//vector<vector<int> >a(50, vector<int>(50));
//vector<vector<int> >book(50, vector<int>(50));
//int n;
//int endx, endy;
//struct node {
//    int x;
//    int y;
//    struct node *f;
//    int s;
//};
//queue <struct node>que;
//int nextNumber[4][2] = {
//    {0, 1},
//    {1, 0},
//    {0, -1},
//    {-1, 0}
//};
//void bfs(int x, int y) {
//    struct node begin;
//    begin.x = x;
//    begin.y = y;
//    begin.f = NULL;
//    begin.s = 0;
//    que.push(begin);
//    int tx = x;
//    int ty = y;
//    int flag = 0;
//    while(!que.empty()) {
//        for (int i = 0 ; i < 4; i++) {
//            tx = que.front().x + nextNumber[i][0];
//            ty = que.front().y + nextNumber[i][1];
//            if (tx < 1 || tx > n || ty < 1 || ty > n) {
//                continue;
//            }
//            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
//                book[tx][ty] = 1;
//                begin.x = tx;
//                begin.y = ty;
//                struct node f = que.front();
//                begin.f = &f;
//                begin.s = que.front().s + 1;
//                que.push(begin);
//            }
//            if (tx == endx && ty == endy) {
//                flag++;
//                break;
//            }
//        }
//        if (flag == 1) {
//            break;
//        }
//        que.pop();
//    }
//    printf("%d", que.back().s);
//}
//int main(int argc, const char * argv[]) {
//    cin >>n;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> a[i][j];
//        }
//    }
//    cin >> endx;
//    cin >> endy;
//    bfs(1, 1);
//}
vector<vector<int> >a(50, vector<int>(50, 0));
vector<vector<int> >book(50, vector<int>(50, 0));
int n;
struct node {
    int x;
    int y;
    int f;
    int s;
};
queue<struct node> que;
int endx = 0, endy = 0;
int nextNumber[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
void bfs(int x, int y) {
    struct node begin;
    begin.x = 0;
    begin.y = 0;
    begin.f = 0;
    begin.s = 0;
    
    vector<struct node> num(50, begin);
    begin.x = x;
    begin.y = y;
    int flag = 0;
    que.push(begin);
    while (!que.empty()) {
        int tx = 0, ty = 0;
        for (int i = 0 ; i < 4; i++) {
            tx = que.front().x + nextNumber[i][0];
            ty = que.front().y + nextNumber[i][1];
            if (tx < 1 || tx > n || ty < 1 || tx > n) {
                continue;
            }
            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                begin.x = tx;
                begin.y = ty;
                begin.f = (int)num.size();
                begin.s = que.front().s + 1;
                que.push(begin);
            }
            if (tx == endx && ty == endy) {
                flag++;
                break;
            }
        }
        que.pop();
        if (flag > 0) {
            break;
        }
    }
    printf("%d", que.front().s);
}
int main(void) {
    cin >>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> endx >> endy;
    bfs(1, 1);
}
