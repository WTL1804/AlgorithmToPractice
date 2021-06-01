//
//  main.cpp
//  二叉树的三种遍历
//
//  Created by 王天亮 on 2021/5/29.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode() :left(nullptr), right(nullptr) {}
};

struct TreeNode * creatNode(void) {
    char ch;
    cin >> ch;
    TreeNode *newNode = new TreeNode();
    if (ch != '#') {
        newNode->val = ch;
        newNode->left = creatNode();
        newNode->right = creatNode();
    } else {
        delete newNode;
        return NULL;
    }
    return newNode;
}
//先序遍历
//void firstFind(TreeNode *root) {
//    vector<TreeNode *>result;
//    TreeNode *p = root;
//    result.push_back(root);
//    while(!result.empty()) {
//        p = result.back();
//        result.pop_back();
//        printf("%c", p->val);
//        if (p->right) {
//            result.push_back(p->right);
//        }
//        if (p->left) {
//            result.push_back(p->left);
//        }
//    }
//    return ;
//}
//中序列遍历
void middleFind(TreeNode *root) {
    vector<TreeNode *>myVector;
    vector<int>result;
    TreeNode *p = root;
    while (!myVector.empty() || p != NULL) {
        while(p) {
            myVector.push_back(p);
            p = p->left;
        }
        p = myVector.back();
        myVector.pop_back();
        result.push_back(p->val);
        printf("%c", p->val);
        p = p->right;
    }
    return ;
}
//后序遍历
//void houxuFind(TreeNode *root) {
//    vector<TreeNode *>s;
//    vector<int> result;
//    TreeNode *p = root;
//    TreeNode *pre = root;
//    while(p || !s.empty()) {
//        while(p) {
//            s.push_back(p);
//            p = p->left;
//        }
//        p = s.back();
//        s.pop_back();
//        if (p->right != NULL && pre != p->right) {
//            s.push_back(p);
//            p = p->right;
//        } else {
//            pre = p;
//            result.push_back(p->val);
//            printf("%c", p->val);
//            p = NULL;
//        }
//    }
//}

//ABC##D##EFG####
int main(int argc, const char * argv[]) {
    TreeNode *root = creatNode();
//    firstFind(root);
    houxuFind(root);
//    middleFind(root);
    return 0;
}
