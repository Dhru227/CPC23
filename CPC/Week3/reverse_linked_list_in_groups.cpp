#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    struct node *reverseIt(struct node *head, int k)
    {
        struct node *current = head;
        struct node *prev = NULL;
        struct node *next = NULL;
        int count = 0;

        struct node *temp = head;
        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }

        if (count == k)
        {
            count = 0;
            while (current != NULL && count < k)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            if (next != NULL)
            {
                head->next = reverseIt(next, k);
            }

            return prev;
        }
        else
        {
            current = head;
            while (current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            return prev;
        }
    }
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }

    return 0;
}
