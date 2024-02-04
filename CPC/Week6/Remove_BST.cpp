#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        if (root->data < l) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }
        if (root->data > r) {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }
        return root;
    }
};

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        int l, r;
        cin >> l >> r;
        string ln;
        getline(cin, ln);
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution obj;
        Node* head = obj.removekeys(root, l, r);
        inorderTraversal(head);
        cout << "\n";
    }
    return 0;
}
