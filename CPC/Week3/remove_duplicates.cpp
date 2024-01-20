#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val == temp->val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head1 = new ListNode(1, new ListNode(1, new ListNode(2)));
    ListNode* head2 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    Solution solution;

    cout << "Original List 1: ";
    printList(head1);
    ListNode* modifiedHead1 = solution.deleteDuplicates(head1);
    cout << "Modified List 1: ";
    printList(modifiedHead1);

    cout << "\nOriginal List 2: ";
    printList(head2);
    ListNode* modifiedHead2 = solution.deleteDuplicates(head2);
    cout << "Modified List 2: ";
    printList(modifiedHead2);

    return 0;
}
