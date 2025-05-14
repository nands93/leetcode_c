#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list3;

    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    if (list1->val <= list2->val) {
        list3 = list1;
        list3->next = mergeTwoLists(list1->next, list2);
    }
    else {
        list3 = list2;
        list3->next = mergeTwoLists(list2->next, list1);
    }
    return (list3);
    
}

int main() {
    struct ListNode* list1;
    struct ListNode* list2;
    struct ListNode* list3;
    struct ListNode* tmp;

    // Creating list1: 1->2->4
    list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    // Creating list2: 1->3->4
    list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    list3 = mergeTwoLists(list1, list2);

    tmp = list3;
    printf("Merged list: ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    while (list3 != NULL)
    {
       tmp = list3;
       list3 = list3->next;
       free(tmp);
    }
    
    return 0;
}