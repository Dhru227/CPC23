#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        vector<int> indegree(K, 0);
        string result = "";

        // Create graph
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += (u + 'a');
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool correct_order = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) correct_order = false;

        if(correct_order) cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
