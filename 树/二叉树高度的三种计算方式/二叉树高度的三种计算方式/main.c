//
//  main.c
//  二叉树高度的三种计算方式
//
//  Created by 王天亮 on 2020/2/21.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>

 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int depth = 0;
int maxDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int heightLeft = maxDepth(root->left);
    int heightRight = maxDepth(root->right);
    if (heightLeft > heightRight) {
        return heightLeft + 1;
    }
    return heightRight + 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
