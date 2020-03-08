//
//  main.c
//  验证二叉树对称
//
//  Created by 王天亮 on 2020/2/29.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
int flag = 0;
void traversA(struct TreeNode *rootA, struct TreeNode *rootB) {
    if (rootA == NULL && rootB == NULL) {
        return;
    }
    if ((rootA == NULL && rootB != NULL) ||(rootA!= NULL && rootB== NULL)) {
        printf("*");
        flag++;
        return;
    }
    printf("%d %d\n", rootA->val, rootB->val);
    if(rootA->val != rootB->val) {
        printf("&");
        flag++;
        return;
    }
    traversA(rootA->left, rootB->right);
    traversA(rootA->right, rootB->left);
}

bool isSymmetric(struct TreeNode* root){
    //要出事后全局变量
    flag = 0;
    if (root == NULL || (!root->left && !root->right)) {
        return true;
    }
    traversA(root->left, root->right);
    if (flag > 0) {
        return false;
    } else {
        return true;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
