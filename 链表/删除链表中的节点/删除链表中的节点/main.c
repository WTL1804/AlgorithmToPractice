//
//  main.c
//  删除链表中的节点
//
//  Created by 王天亮 on 2020/3/30.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*p = head;
    if (p->next == NULL) {
        return NULL;
    }
    int temp = 0;
    struct ListNode*q = head->next;
    while(q->next != NULL) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            q = q->next;
            if (q == NULL && i == n - 1) {
                flag++;
                break;
            }
            if (q == NULL) {
                temp++;
                break;
            }
        }
        if (temp != 0) {
            // p = head;
            // q = head->next;
            break;
        }
         q = p->next;
        if (flag != 0 && n != 1) {

                p->next = q->next;
                q->next = NULL;
                return head;
        }
        q = q->next;
        p = p->next;
    }
    if (temp != 0) {
        return head->next;
    }
     if (n == 1 && q->next == NULL) {
            p->next = NULL;
            return head;
        }
    if (n == 2 && q->next == NULL) {
        return q;
    }
    if (q->next == NULL) {
        return p;
    }
    return head;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode*p = l1;
    struct ListNode*q = l2;
    struct ListNode*m;
    if (l1 == NULL || l2 == NULL) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL && l2 != NULL) {
            return l2;
        } else {
            return l1;
        }
    }
    if (l1->val >= l2->val) {
        m = l2;
        q = q->next;
    } else {
        m = l1;
        p = p->next;
    }
    struct ListNode*n = m;
    int flag = 0, temp = 0;
    while(1) {
         if (p == NULL) {
            flag++;
            break;
        }
        if (q == NULL) {
            temp++;
            break;
        }
        if (p->val >= q->val) {
            n->next = q;
            q = q->next;
        } else {
            n->next = p;
            p = p->next;
        }
        n = n->next;
       
    }

    if (temp != 0 && p!= NULL) {
        while(p) {
            n->next = p;
            n = n->next;
            p = p->next;
        }
    }
    if (flag != 0 && q!= NULL) {
        while(q) {
            n->next = q;
            n = n->next;
            q = q->next;
        }
    }
    return m;
}



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
