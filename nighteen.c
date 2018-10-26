#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int length = 0;
    struct ListNode* tmp = head;
    while(tmp != NULL){
        tmp = tmp->next;
        length++;
    }
    if(n > length) {
        return NULL;
    }else if(n == length){
        return head->next;
    }
    int k = length - n ;
    int i;
    tmp = head;
    for(i = 0 ; i < k-1; i++){
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;

    printf("length = %d\n",length);
    return head;
}
struct ListNode* removeNthFromEndBetter(struct ListNode* head, int n){
    struct ListNode* p= head;
    struct ListNode* q= head;
    while( p && n){
        p = p->next;
        n--;
    }
    if(p == NULL){
        free(head);
        return head->next;
    }
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    p = q->next;
    q->next = q->next->next;
    free(p);
    return head;
}
int main()
{
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* l4 = malloc(sizeof(struct ListNode));
    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l4->val = 4;
    l4->next = NULL; 
    l3->next = l4;
    l2->next = l3;
    l1->next = l2;
    removeNthFromEndBetter(l1, 2);
    struct ListNode* l = l1;
    while(l != NULL){
        printf("%d->",l->val);
        l = l->next;
    }
    printf("\n");
}
