#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* pre = dummy;
    struct ListNode* cur = head;

    while (cur != NULL) {
        while (cur->next != NULL && cur->val == cur->next->val) {
            cur = cur->next;
        }
        if (pre->next == cur) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
        }
        cur = cur->next;
    }
    return dummy->next;
}

int main() {
    struct ListNode* head ; // initialize linked list
    struct ListNode* res = deleteDuplicates(head);
    if (res == NULL) {
        printf("None\n");
        return 0;
    }

    // print result linked list
    while (res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }

    return 0;
}