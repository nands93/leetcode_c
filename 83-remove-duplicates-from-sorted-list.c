#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return (head);
    }

    if (head->val == head->next->val) {
        struct ListNode* temp = head->next;
        head->next = head->next->next;
        free(temp);
        return deleteDuplicates(head);
    } else {
        head->next = deleteDuplicates(head->next);
        return (head);
    }
    return (head);
}

int main() {
    struct ListNode* head;
    struct ListNode* tmp;

    // Creating a sorted linked list: 1->1->2->3->3
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 1;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 2;
    head->next->next->next->next->next = NULL;

    head = deleteDuplicates(head);

    tmp = head;
    printf("List after removing duplicates: ");
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    // Free the remaining nodes
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}