#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node *node) {
    if(node == NULL)
        return;
    
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

class Solution {
  public:
    int toSumTreeHelper(Node* node) {
        if (node == NULL) return 0;
        if (node->left == NULL && node->right == NULL) return node->data;
        
        int leftSum = toSumTreeHelper(node->left);
        int rightSum = toSumTreeHelper(node->right);
        
        int temp = node->data;
        node->data = leftSum + rightSum;
        
        return temp + node->data;
    }
    
    void toSumTree(Node *node) {
        if (node == NULL) return;
        
        toSumTreeHelper(node);
        updateLeafNodes(node);
    }
    
    void updateLeafNodes(Node* node) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) {
            node->data = 0;
            return;
        }
        
        updateLeafNodes(node->left);
        updateLeafNodes(node->right);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while(t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout << endl;
    }
    return 0;
}
