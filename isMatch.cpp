#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};

int main() {
    Solution sol;
    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";
    string s3 = "ab", p3 = ".*";
    
    cout << sol.isMatch(s1, p1) << endl; // Output: false
    cout << sol.isMatch(s2, p2) << endl; // Output: true
    cout << sol.isMatch(s3, p3) << endl; // Output: true
    
    return 0;
}
