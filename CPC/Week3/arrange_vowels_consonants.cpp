#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL) return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node** headRef, char data)
{
    struct Node* new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

struct Node* arrange(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node *vowelHead = NULL, *vowelTail = NULL;
    struct Node *consonantHead = NULL, *consonantTail = NULL;

    struct Node *current = head;

    while (current != NULL) {
        if (current->data == 'a' || current->data == 'e' || current->data == 'i' ||
            current->data == 'o' || current->data == 'u') {
            if (vowelHead == NULL) {
                vowelHead = current;
                vowelTail = current;
            } else {
                vowelTail->next = current;
                vowelTail = current;
            }
        } else {
            if (consonantHead == NULL) {
                consonantHead = current;
                consonantTail = current;
            } else {
                consonantTail->next = current;
                consonantTail = current;
            }
        }

        current = current->next;
    }

    if (vowelHead == NULL) {
        return consonantHead;
    }

    vowelTail->next = consonantHead;
    if (consonantTail != NULL) {
        consonantTail->next = NULL;
    }

    return vowelHead;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
    return 0;
}
