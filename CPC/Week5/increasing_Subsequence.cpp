#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxLength(string S) {
        int n = S.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (S[i] > S[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0;
}
