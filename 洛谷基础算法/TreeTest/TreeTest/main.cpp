//
//  main.cpp
//  TreeTest
//
//  Created by 王天亮 on 2020/10/16.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct treeNode {
    char s;
    struct treeNode *leftNode;
    struct treeNode *rightNode;
};
int len = 0;
struct treeNode * creat(string str) {
        struct treeNode *tree;
        if (len > str.size() - 1) {
            return NULL;
        }
        if (str[len] == '#') {
            len++;
            tree = NULL;
        } else if (str[len] == ' '){
            len++;
            tree = NULL;
        } else {
            tree = (struct treeNode *)malloc(sizeof(struct treeNode));
            tree->s = str[len];
            len++;
            tree->leftNode = creat(str);
            tree->rightNode = creat(str);
        }
    return tree;
}
//先序遍历
void firstFind(struct treeNode *root) {
    if (root == NULL) {
        return ;
    }
    printf("%c ", root->s);
    firstFind(root->leftNode);
    firstFind(root->rightNode);
}
//中序遍历
void middleFind(struct treeNode *root) {
    if (root == NULL) {
        return ;
    }
    middleFind(root->leftNode);
    printf("%c ", root->s);
    middleFind(root->rightNode);
}
//后序遍历
void lastFind(struct treeNode *root) {
    if (root == NULL) {
        return ;
    }
    lastFind(root->leftNode);
    lastFind(root->rightNode);
    printf("%c ", root->s);
}





//三种遍历的迭代写法
//先序遍历
//void firstFindIteration(struct treeNode *root) {
//    stack<struct treeNode *> sta;
//    struct treeNode *tree = root;
//    sta.push(tree);
//    printf("%c", tree->s);
//    tree = tree->leftNode;
//    while(!sta.empty() || tree != NULL) {
//        if (tree == NULL) {
//            tree = sta.top();
//            sta.pop();
//            tree = tree->rightNode;
//            continue;
//        }
//        printf("%c", tree->s);
//        sta.push(tree);
//        tree = tree->leftNode;
//    }
//}
////中序遍历
//void middleFindeIteration(struct treeNode *root) {
//    stack<struct treeNode *>sta;
//    struct treeNode *tree = root;
//    sta.push(tree);
//    tree = tree->leftNode;
//    while (!sta.empty() || tree != NULL) {
//        if (tree == NULL) {
//            tree = sta.top();
//            printf("%c ", tree->s);
//            tree = tree->rightNode;
//            sta.pop();
//            continue;
//        }
//        sta.push(tree);
//        tree = tree->leftNode;
//    }
//}
////后序遍历
//void lastFindIteration(struct treeNode *root) {
//    stack<struct treeNode *> sta;
//    stack<struct treeNode *> sta2;
//    struct treeNode *tree = root;
//    sta.push(tree);
//    tree = tree->leftNode;
//    while (!sta.empty() || tree != NULL) {
//        if (tree == NULL) {
//            tree = sta.top();
//            tree = tree->rightNode;
//            if (tree == NULL) {
//                printf("%c ", sta.top()->s);
//                while(!sta2.empty()) {
//                    printf("%c ", sta2.top()->s);
//                    sta2.pop();
//                }
//            } else {
//                sta2.push(sta.top());
//            }
//            sta.pop();
//            continue;
//        }
//        sta.push(tree);
//        tree = tree->leftNode;
//    }
//}
void lastFindIteration(struct treeNode *root) {
    stack<struct treeNode *> sta;
    stack<struct treeNode *> temp;
    struct treeNode *tree = root;
    while(!sta.empty() || tree != NULL) {
        if (tree == NULL) {
            tree = sta.top();
            sta.pop();
            if (tree->rightNode == NULL) {
                printf("%c ", tree->s);
                while(!temp.empty()) {
                    struct treeNode *tem = temp.top();
                    printf("%c ", tem->s);
                    temp.pop();
                }
            } else {
                temp.push(tree);
            }
            tree = tree->rightNode;
            continue;
        }
        //printf("%c ", root->s);
        sta.push(tree);
        tree = tree->leftNode;
    }
}
int main(int argc, const char * argv[]) {
//    string s = "ABC#E##D##F##";
    //len = (int)s.size();
//    struct treeNode *root = (struct treeNode *)malloc(sizeof(struct treeNode));
//    root = creat(s);
////  firstFind(root);
////  middleFind(root);
//    lastFind(root);
//    printf("\n");
////  firstFindIteration(root);
////  middleFindIteration(root);
//    lastFindIteration(root);
//    int a[5] = {1, 2, 3, 4, 5};
//    for (int i = 0; i < 5; i++) {
//        printf("%d", a[i]);
//    }
//    int n;
   // int arr[3] = {0};
    int i = 0;
   // int a = 0;
    //int c = 0;
//        int arr[3] = {0};
    int arr2[3] = {5};
 //   printf("%p\n", &i);
//    printf("%p\n", &n);
//    printf("%p\n", &a);
//    printf("%p\n", &c);
        for (; i <= 3;i++) {
            arr2[i] = 0;//
//            printf("hello world\n");
         //   printf("%p\n", &arr[i]);
        }
   // printf("%p\n", &arr2[0]);
        return 0;
}
