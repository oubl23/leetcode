#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;

};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    struct ListNode* l = malloc(sizeof(struct ListNode));
    struct ListNode* tmp = l;
    struct ListNode* tmp2 = NULL;
    while(l1 || l2){
        if(l1 && l2){
            if(l1->val > l2->val){
                tmp->val = l2->val;
                l2 = l2->next;
            }else{
                tmp->val = l1->val;
                l1 = l1->next;
            }
        }else if(l1){
            tmp->val = l1->val;
            l1 = l1->next;
        }else if(l2){
            tmp->val = l2->val;
            l2 = l2->next;
        }
        if(l1 || l2){
            tmp2 = malloc(sizeof(struct ListNode));
            tmp->next = tmp2; 
            tmp = tmp2;
        }else{
            tmp->next = NULL;
        }
    }
    return l;
}
