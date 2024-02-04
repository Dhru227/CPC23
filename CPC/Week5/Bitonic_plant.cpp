#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findMaximum(int arr[], int n) {
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return arr[low];
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
        int ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
