#include <iostream>
#include <algorithm> 4

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k-1; i++) {
            right_ptr = right_ptr->next;
        }
        
        ListNode *end_ptr = right_ptr;
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        std::swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k1 = 2;

    ListNode* head2 = new ListNode(7, new ListNode(9, new ListNode(6, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(3, new ListNode(0, new ListNode(9, new ListNode(5))))))))));
    int k2 = 5;

    Solution solution;

    ListNode* swappedHead1 = solution.swapNodes(head1, k1);
    ListNode* swappedHead2 = solution.swapNodes(head2, k2);

    std::cout << "Original Linked List 1: ";
    printList(head1);

    std::cout << "Swapped Linked List 1: ";
    printList(swappedHead1);

    std::cout << "Original Linked List 2: ";
    printList(head2);

    std::cout << "Swapped Linked List 2: ";
    printList(swappedHead2);

    return 0;
}
