#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* penultimate = head;
        while (penultimate->next->next) penultimate = penultimate->next;

        penultimate->next->next = head->next;
        head->next = penultimate->next;

        penultimate->next = NULL;

        reorderList(head->next->next);
    }
};

int main() {
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution sol;
    sol.reorderList(head1);

    ListNode* current = head1;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
