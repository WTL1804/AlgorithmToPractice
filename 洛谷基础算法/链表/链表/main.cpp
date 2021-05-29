//
//  main.cpp
//  链表
//
//  Created by 王天亮 on 2020/11/2.
//

#include <iostream>
struct node {
    int val;
    struct node *next;
};
using namespace std;
struct node * merg(struct node *headOne, struct node *headTwo) {
    struct node *head = headOne, *one, *two;
    one = headOne;
    two = headTwo;
    if (headOne == NULL && headTwo == NULL) {
        return NULL;
    }
    if (headOne->val > headTwo->val) {
        head = headOne;
        one = one->next;
    }
    if (headOne->val <= headTwo->val) {
        head = headTwo;
        two = two->next;
    }
    struct node *h = head;
    while(one != NULL && two != NULL) {
        if (one->val > two->val) {
            head->next = one;
            one = one->next;
            
        }
        if (one->val <= two->val) {
            head->next = two;
            two = two->next;
        }
        head = head->next;
    }
    if (one != NULL) {
        head->next = one;
    }
    if (two != NULL) {
        head->next = two;
    }
    return h;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
}
