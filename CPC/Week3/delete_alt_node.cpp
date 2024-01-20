#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void deleteAlt(struct Node *head){
    if (head == NULL || head->next == NULL) {
        return; 
    }

    struct Node *current = head;
    struct Node *nextNode = NULL;

    while (current != NULL && current->next != NULL) {
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
        current = current->next;
    }
}

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    struct Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        struct Node* head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        deleteAlt(head);
        printList(head);
    }
    return 0;
}
