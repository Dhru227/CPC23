#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node** r) {
    Node* prev = NULL;
    Node* cur = *r;
    Node* nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

void freeList(Node* Node) {
    Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        delete temp;
    }
}

long long multiplyTwoLists(Node* l1, Node* l2) {
    const int MOD = 1e9 + 7;
    long long num1 = 0, num2 = 0;

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            num1 = (num1 * 10 + l1->data) % MOD;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            num2 = (num2 * 10 + l2->data) % MOD;
            l2 = l2->next;
        }
    }

    return (num1 * num2) % MOD;
}

int main() {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* first = NULL;
        struct Node* second = NULL;

        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first, second);

        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}
