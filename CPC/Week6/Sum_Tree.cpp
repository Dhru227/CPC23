#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    pair<int, bool> isSumTreeHelper(Node* root) {
        if (root == nullptr)
            return {0, true};

        if (root->left == nullptr && root->right == nullptr)
            return {root->data, true};

        auto left = isSumTreeHelper(root->left);
        auto right = isSumTreeHelper(root->right);

        int sum = root->data + left.first + right.first;
        bool isSum = (root->data == sum - root->data) && left.second && right.second;

        return {sum, isSum};
    }

    bool isSumTree(Node* root) {
        if (root == nullptr)
            return true;

        auto result = isSumTreeHelper(root);
        return result.second;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumTree(root) << endl;
    }
    return 0;
}
