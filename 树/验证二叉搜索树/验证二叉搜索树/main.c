//
//  main.c
//  验证二叉搜索树
//
//  Created by 王天亮 on 2020/2/29.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
bool isValidBST(struct TreeNode* root) {
    struct TreeNode * s[100000];
    int number [100000];
    int t = 0;
    int top = 0;
    s[top++] = root;
    if (root == NULL) {
        return true;
    }
    if (!root->left && !root->right) {
        return true;
    }
    if (root->left) {
        root = root->left;
    } else{
        number[t++] = root->val;
        root = root->right;
        //当左子树为空时，很关键
      top = 0;
        printf("%d\n", number[t - 1]);
    }
    while(root || top > 0) {
        while(root) {
            s[top++] = root;
            root = root->left;
        }
        root = s[--top];
         number[t++] = root->val;
        printf("%d\n", root->val);
        if ( t > 1 && number[t - 1] <= number[t-2]  ) {
            return false;
        }
        root = root->right;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
