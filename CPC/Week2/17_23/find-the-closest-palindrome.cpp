#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);

        auto makePalindrome = [](string root, int len) {
            root += string(root.rbegin() + len % 2, root.rend());
            return root;
        };

        auto diff = [](long long a, long long b) {
            return abs(a - b);
        };

        string root = n.substr(0, (n.length() + 1) / 2);
        long long numRoot = stoll(root);
        
        set<long long> candidates{static_cast<long long>(pow(10, n.length()) + 1), static_cast<long long>(pow(10, n.length() - 1) - 1)};

        for (int i = -1; i <= 1; ++i) {
            string candidate = to_string(numRoot + i);
            candidates.insert(stoll(makePalindrome(candidate, n.length())));
        }

        candidates.erase(num);  

        long long minDiff = LLONG_MAX;
        string result;

        for (long long candidate : candidates) {
            long long candidateDiff = diff(candidate, num);
            if (candidateDiff < minDiff || (candidateDiff == minDiff && candidate < stoll(result))) {
                minDiff = candidateDiff;
                result = to_string(candidate);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    string n = "12345";
    cout << "Nearest palindrome to " << n << " is: " << solution.nearestPalindromic(n) << endl;

    return 0;
}
