#include <iostream>
using namespace std;

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
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;  // Free memory of removed node
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
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
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
ListNode* head2 = new ListNode(1);
head2->next = new ListNode(1);
head2->next->next = new ListNode(1);
head2->next->next->next = new ListNode(2);
head2->next->next->next->next = new ListNode(3);

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
