#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

void findOrder(vector<string> v) {
    int n = v.size();
    if (n == 1) {
        cout << "abcdefghijklmnopqrstuvwxyz";
        return;
    }
    vector<int> adj[MAX_CHAR];
    vector<int> in(MAX_CHAR, 0);
    string prev = v[0];
    for (int i = 1; i < n; ++i) {
        string s = v[i];
        int j;
        for (j = 0; j < min(prev.length(), s.length()); ++j)
            if (s[j] != prev[j])
                break;
        if (j < min(prev.length(), s.length())) {
            adj[prev[j] - 'a'].push_back(s[j] - 'a');
            in[s[j] - 'a']++;
            prev = s;
            continue;
        }
        if (prev.length() > s.length()) {
            cout << "Impossible";
            return;
        }
        prev = s;
    }
    stack<int> stk;
    for (int i = 0; i < MAX_CHAR; ++i)
        if (in[i] == 0)
            stk.push(i);
    vector<char> out;
    bool vis[26];
    memset(vis, false, sizeof(vis));
    while (!stk.empty()) {
        char x = stk.top();
        stk.pop();
        vis[x] = true;
        out.push_back(x + 'a');
        for (int i = 0; i < adj[x].size(); ++i) {
            if (vis[adj[x][i]])
                continue;
            in[adj[x][i]]--;
            if (in[adj[x][i]] == 0)
                stk.push(adj[x][i]);
        }
    }
    for (int i = 0; i < MAX_CHAR; ++i)
        if (!vis[i]) {
            cout << "Impossible";
            return;
        }
    for (int i = 0; i < out.size(); ++i)
        cout << out[i];
}

int main() {
    vector<string> v{ "efgh", "abcd" };
    findOrder(v);
    return 0;
}
