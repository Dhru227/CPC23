#include <iostream>

struct Node
{
    int data;
    struct Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution
{
public:
    bool detectLoop(Node* head)
    {
        Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;  
            }
        }

        return false;  
    }
};

int main()
{
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; 

    Solution obj;
    if (obj.detectLoop(head)) {
        std::cout << "Linked list has a loop.\n";
    } else {
        std::cout << "Linked list does not have a loop.\n";
    }

    delete head->next->next->next->next; 
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
