#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *a;
struct Node *b;

void append(struct Node **headRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

void alternatingSplitList(struct Node *head)
{
    struct Node *current = head;
    struct Node *aTail = NULL;
    struct Node *bTail = NULL;
    struct Node *temp;

    while (current != NULL)
    {
        if (aTail == NULL)
        {
            a = current;
            aTail = current;
        }
        else
        {
            aTail->next = current;
            aTail = current;
        }

        temp = current->next;
        if (temp != NULL)
        {
            current->next = temp->next;
            current = temp;
        }
        else
        {
            break;
        }

        if (bTail == NULL)
        {
            b = temp;
            bTail = temp;
        }
        else
        {
            bTail->next = temp;
            bTail = temp;
        }
    }

    if (aTail != NULL)
        aTail->next = NULL;
    if (bTail != NULL)
        bTail->next = NULL;
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        a = b = NULL;
        struct Node *head = NULL;

        int n, k;
        cin >> n;

        while (n--)
        {
            cin >> k;
            append(&head, k);
        }

        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}
