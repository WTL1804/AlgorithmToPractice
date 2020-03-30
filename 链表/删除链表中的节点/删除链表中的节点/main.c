//
//  main.c
//  删除链表中的节点
//
//  Created by 王天亮 on 2020/3/30.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    if (!p) {
        node = NULL;
    } else if (!p->next){
        node->val = p->val;
        node->next = NULL;
    } else {
        node->val = p->val;
        node->next = p->next;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
