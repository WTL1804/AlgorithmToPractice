//
//  main.c
//  二叉树的创建
//
//  Created by 王天亮 on 2020/7/21.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
   char val;
   struct TreeNode *left;
   struct TreeNode *right;
};
//创建二叉树
struct TreeNode * createTree() {
    char ch;
    scanf("%c", &ch);
    struct TreeNode *new = (struct TreeNode *)malloc(sizeof(struct TreeNode) * 1);
    if (ch != '#') {
    
        new->val = ch;
        new ->left = createTree();
        new ->right = createTree();
    } else {
        return NULL;
    }
    return new;
}
//先序遍历二叉树
void traverseRoot(struct TreeNode *root) {
    if (root != NULL) {
        printf("%c", root->val);
        traverseRoot(root->left);
        traverseRoot(root->right);
    }
}

//根据先序和中序创建二叉树
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize == 0) {
        return NULL;
    }
    int all, num = preorderSize;
     struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    while(num--) {
        if (inorder[num] == preorder[0]) {
            break;
        }
    }
    all = num + 1;
    node->left = buildTree(preorder + 1, num, inorder, num);
    node->right = buildTree(preorder + all, preorderSize - all, inorder + all, inorderSize - all);
    return node;
}
int main(int argc, const char * argv[]) {
    struct TreeNode *root = createTree();
   // createTree(root);
    traverseRoot(root);
    return 0;
}
