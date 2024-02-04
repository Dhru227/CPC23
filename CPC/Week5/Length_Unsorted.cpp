#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:    
    vector<int> printUnsorted(int arr[], int n) {
        vector<int> result(2, 0);
        int start = 0, end = n - 1;

        while (start < n - 1 && arr[start] <= arr[start + 1]) {
            start++;
        }

        if (start == n - 1) return result;

        while (end > 0 && arr[end] >= arr[end - 1]) {
            end--;
        }

        int max_in_subarray = INT_MIN, min_in_subarray = INT_MAX;
        for (int i = start; i <= end; i++) {
            max_in_subarray = max(max_in_subarray, arr[i]);
            min_in_subarray = min(min_in_subarray, arr[i]);
        }

        while (start > 0 && arr[start - 1] > min_in_subarray) {
            start--;
        }

        while (end < n - 1 && arr[end + 1] < max_in_subarray) {
            end++;
        }

        result[0] = start;
        result[1] = end;

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
