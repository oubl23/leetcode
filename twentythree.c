#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
int getMinVal(struct ListNode** lists,int listSize){
    int k = -1;
    int min = INT_MAX;
    int i;
    for(i = 0; i < listSize; i++){
        if(lists[i] && lists[i]->val <= min){
            k = i;
            min = lists[i]->val;
        }
    }
    if(k > -1){
        lists[k] = lists[k]->next;
        return min;
    }

}
struct ListNode* mergeKLists(struct ListNode** lists, int listSize){
    if( listSize == 0){
        return NULL;
    }
    if( listSize == 1){
        return lists[0];
    }
    int k, i;
    int min;
    struct ListNode* l = malloc(sizeof(struct ListNode));

    struct ListNode* p,* q = l;

    while(k != -1){
        k = -1;
        min = INT_MAX;
        for(i = 0; i < listSize; i++){
            if(lists[i] && lists[i]->val <= min){
                k = i;
                min = lists[i]->val;
            }
        }
        if(k > -1){
            p = malloc(sizeof(struct ListNode));
            lists[k] = lists[k]->next;
            p->val = min;
            p->next = NULL;
        }else{
            p = NULL;
        }
        q->next = p;
        q = p;
    }
    return l->next;
}

struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    struct ListNode* l;
    l = NULL;
    if(l1->val < l2->val){
        l = l1;
        l->next = mergeLists(l1->next, l2);
    }else{
        l = l2;
        l->next = mergeLists(l2->next,l1);
    }
    return l;
}

struct ListNode* mergeKListsBetter(struct ListNode** lists, int listsSize){
    if(listsSize <= 0)  return NULL;
    if(listsSize == 1)  return lists[0];
    
    while(listsSize > 1){
        struct ListNode** newLists = lists;
        int count = listsSize / 2;
        int slice = listsSize % 2;
        int i;
        for(i = 0; i < count; i++){
            struct ListNode* tmp = mergeLists(lists[2*i], lists[2*i+1]);
            newLists[i] = tmp;
        }
        if(listsSize % 2 == 1){
            newLists[i] = lists[listsSize -1];
        }
        lists = newLists;
        listsSize = count + slice;
    }
    return lists[0];
}

int main(){
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* l4 = malloc(sizeof(struct ListNode));
    struct ListNode* l5 = malloc(sizeof(struct ListNode));
    struct ListNode* l6 = malloc(sizeof(struct ListNode));
    l6->val = 6;
    l6->next = 0;
    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l4->val = 4;
    l5->val = 5;
    l2->next = NULL;
    l5->next = NULL;
    l4->next = l5;
    l3->next = l4;
    l1->next = l2;
    struct ListNode* lists[3];
    lists[0] = l1;
    lists[1] = l3;
    lists[2] = l6;
    struct ListNode* l = mergeKLists(lists,3);
    while(l){
        printf("%d->",l->val);
        l = l->next;
    }
    printf("\n");

}
