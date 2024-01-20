#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSum(vector<int> &a, vector<int> &b) {
        vector<int> result;
        int carry = 0;

        int n = a.size();
        int m = b.size();

        if (n < m) {
            swap(a, b);
            swap(n, m);
        }

        for (int i = 0; i < n; i++) {
            int sum = a[i];
            if (i < m) {
                sum += b[i];
            }
            sum += carry;

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
