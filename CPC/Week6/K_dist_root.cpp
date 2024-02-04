#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> result;
    if (root == NULL || k < 0)
        return result;
    
    if (k == 0)
    {
        result.push_back(root->data);
        return result;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        if (level == k)
        {
            while (size--)
            {
                Node* current = q.front();
                q.pop();
                result.push_back(current->data);
            }
            return result;
        }

        while (size--)
        {
            Node* current = q.front();
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        level++;
    }

    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int k;
        scanf("%d", &k);
        string s;
        getline(cin, s);
        struct Node* root = buildTree(s);
        vector<int> vec = Kdistance(root, k);
        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
