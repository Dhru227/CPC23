#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

class Solution{
public:
    TNode* sortedListToBST(LNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TNode(head->data);
        
        LNode* slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev) prev->next = NULL; 
        
        TNode* root = new TNode(slow->data);
        root->left = sortedListToBST(head); 
        root->right = sortedListToBST(slow->next); 
        
        return root;
    }
};

int main() 
{ 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
    }
    return 0;
}
