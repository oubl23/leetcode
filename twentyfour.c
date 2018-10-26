#include "leetcode.h"

struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* p1;
    p1 = head->next;
    head->next = p1->next;
    p1->next = head;
    head = p1;
    head->next->next = swapPairs(head->next->next);
    return head;
}

struct ListNode* swapPairsBetter(struct ListNode* head){
    if(!head){
        return NULL;
    }
    struct ListNode *p1 = head , *p2=head->next, *pre = NULL;
    while(p2){
        p1->next = p2->next;
        p2->next = p1;
        pre ? (pre->next = p2) :(head = p2);
        pre = p1;
        p1 = p1->next;
        p2 = p1? p1->next:NULL;
    }
    return head;
}

void printNode(struct ListNode* l){
    while(l){
        printf("%d->",l->val);
        l = l->next;
    }
    printf("\n");
}

int main(void){
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* l4 = malloc(sizeof(struct ListNode));
    struct ListNode* l5 = malloc(sizeof(struct ListNode));
    struct ListNode* l6 = malloc(sizeof(struct ListNode));
    struct ListNode* l7 = malloc(sizeof(struct ListNode));
    struct ListNode* l = malloc(sizeof(struct ListNode));
    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l4->val = 4;
    l5->val = 5;
    l6->val = 6;
    l7->val = 7;
    l7->next = NULL;
    l6->next = l7;
    l5->next = l6;
    l4->next = l5;
    l3->next = l4;
    l2->next = l3;
    l1->next = l2;
    printNode(l1);
    l = swapPairsBetter(l1);
    printNode(l);
}

