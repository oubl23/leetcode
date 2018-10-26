#include "leetcode.h"
struct ListNode* reverseK(struct ListNode *head ,int k){
    struct ListNode* p = head->next, *pre = head, *next = p->next;
    while(k > 1 && p){
        p->next = head;
        head = p;
        pre->next = next;
        p = next;
        next = p->next;
        k--;
    }
    return head;
}
struct ListNode* reverseK2(struct ListNode *head ,int k){
    struct ListNode *q = head->next, *p = q->next, *pre = q, *next = p;
    while(k > 1 && next){
        p = next;
        next = p->next;
        p->next = q;
        q = p;
        pre->next = next;
        k--;
    }
    head->next = q;
    return head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *q = head, *p = q->next, *pre = q, *next = p, *t = NULL;
    int n;
    while(1){
        n = k;
        while(n>1 && next){
            p = next;
            next = p->next;
            p->next = q;
            q = p;
            pre->next = next;
            n--;
        }
        if(t){
            t->next = q;
        }else{
            head = q;
        }
        break;
        t = p;
        //q = t->next;
        //p = q->next;
        //pre = q;
        //next = p->next;
        if(next == NULL)
            break;
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
int main(void)
{
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
    l = reverseK2(l1,10);
    printNode(l);
} 
