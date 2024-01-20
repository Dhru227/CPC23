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
    Node* sortList(Node* head) {
        int count[3] = {0};
        Node* current = head;

        while (current != NULL) {
            count[current->data]++;
            current = current->next;
        }

        current = head;
        for (int i = 0; i < 3; i++) {
            while (count[i] > 0) {
                current->data = i;
                current = current->next;
                count[i]--;
            }
        }

        return head;
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
        int n;
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

        Solution ob;
        head = ob.sortList(head);
        printList(head);
    }

    return 0;
}
