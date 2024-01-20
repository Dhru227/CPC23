#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        if (head == NULL || k <= 0)
        {
            return head;
        }

        int length = 1;
        Node *current = head;
        while (current->next != NULL)
        {
            length++;
            current = current->next;
        }

        k = k % length;
        if (k == 0)
        {
            return head;
        }

        int stepsToNewHead = length - k;
        current = head;
        while (stepsToNewHead > 1)
        {
            current = current->next;
            stepsToNewHead--;
        }

        Node *newHead = current->next;
        current->next = NULL;
        current = newHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = head;

        return newHead;
    }
};

// Function to print the linked list
void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}
