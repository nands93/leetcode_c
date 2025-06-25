//https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    int num1 = 0;
    int num2 = 0;
    int carry = 0;
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* curr = l3;
    while (l1 != NULL || l2 != NULL) {
        num1 = 0;
        num2 = 0;
        if (l1 != NULL) {
            num1 = l1->val;
            l1 = l1->next;
            printf("num1 = %d\n", num1);
        }
        if (l2 != NULL) {
            num2 = l2->val;
            l2 = l2->next;
            printf("num2 = %d\n", num2);
        }
        sum = num1 + num2 + carry;
        curr->val = sum % 10;
        printf("curr->val = %d\n", curr->val);
        carry = sum / 10;
        printf("carry = %d\n", carry);
        if ((l1 != NULL) || (l2 != NULL)) {
            curr->next = malloc(sizeof(struct ListNode));
            curr = curr->next;
        }
        else {
            curr->next = NULL;
        }
    }
    if (carry != 0) {
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = carry;
        curr->next = NULL;
    }
    return l3;
}

int main() {
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    
    // Creating first linked list: 2 -> 4 -> 3 (represents the number 342)
    // 9,9,9,9,9,9,9
    l1->val = 9;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 9;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 9;
    l1->next->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->next->val = 9;
    l1->next->next->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->next->next->val = 9;
    l1->next->next->next->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->next->next->next->val = 9;
    l1->next->next->next->next->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->next->next->next->next->val = 9;
    l1->next->next->next->next->next->next->next = NULL;

    // Creating second linked list: 5 -> 6 -> 4 (represents the number 465)
    l2->val = 9;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 9;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 9;
    l2->next->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->next->val = 9;
    l2->next->next->next->next = NULL;

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result linked list: ");
    while (result != NULL) {
        printf("%d ", result->val);
        struct ListNode* temp = result;
        result = result->next;
        free(temp);
    }
    printf("\n");

    // Free the input lists
    free(l1->next->next);
    free(l1->next);
    free(l1);
    
    free(l2->next->next);
    free(l2->next);
    free(l2);

    return 0;
}