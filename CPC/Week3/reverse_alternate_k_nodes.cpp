#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverseAlternateKNodes(Node* head, int k) {
        Node* current = head;
        Node* next = NULL;
        Node* prevTail = NULL;
        Node* newHead = NULL;
        bool reverse = true;

        while (current != NULL) {
            int count = 0;
            Node* tail = current;
            Node* prev = NULL;

            while (current != NULL && count < k) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            if (reverse && newHead == NULL) {
                newHead = prev;
            }

            if (prevTail != NULL) {
                prevTail->next = prev;
            }

            prevTail = tail;

            count = 0;
            while (current != NULL && count < k) {
                prevTail = current;
                current = current->next;
                count++;
            }

            reverse = !reverse;
        }

        return newHead;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;

        Node* head = NULL;
        Node* tail = NULL;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;

            if (head == NULL) {
                head = new Node(value);
                tail = head;
            } else {
                tail->next = new Node(value);
                tail = tail->next;
            }
        }

        cin >> k;

        Solution ob;
        head = ob.reverseAlternateKNodes(head, k);
        printList(head);
    }

    return 0;
}
