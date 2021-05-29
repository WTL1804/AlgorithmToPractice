//
//  main.cpp
//  从俩中序列构造二叉树
//
//  Created by 王天亮 on 2020/11/30.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
unordered_map<int, int> indexMap;
TreeNode * creat(vector<int> &first, vector<int> &middle, int firstLeft, int firstRight, int middleLeft, int middleRight) {
    if (firstLeft > firstRight) {
        return NULL;
    }
    int leftRoot = firstLeft;
    int middleRoot = indexMap[first[leftRoot]];
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = first[firstLeft];
    int sizeLeft = middleRoot - middleLeft;
    root->left = creat(first, middle, firstLeft + 1, firstLeft + sizeLeft, middleLeft, middleRoot - 1);
    root->right = creat(first, middle, firstLeft + sizeLeft + 1, firstRight, middleRoot + 1, middleRight);
    return root;
}
int main(int argc, const char * argv[]) {
//    vector<int> a;
//    vector<int> b;
//    int m = 0, n = 0;
//    cin>>n >>m;
//    for (int i = 0; i < n; i++) {
//        int temp = 0;
//        cin >> temp;
//        a.push_back(temp);
//    }
//    for (int j = 0; j < m; j++) {
//        int temp = 0;
//        cin >>temp;
//        b.push_back(temp);
//    }
    unordered_map<int, int>map;
    printf("%d", map[0]);
    return 0;
}

