#include <bits/stdc++.h>
using namespace std;

vector<int> get2NonRepeatingNos(int nums[], int n) {
    sort(nums, nums + n);

    vector<int> ans;
    int i = 0;
    
    while (i < n - 1) {
        if (nums[i] != nums[i + 1]) {
            ans.push_back(nums[i]);
            i++;
        } else {
            i += 2;  // Skip the repeated elements
        }
    }

    if (i == n - 1) {
        ans.push_back(nums[i]);
    }

    return ans;
}

int main() {
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = sizeof(arr) / sizeof(*arr);
    
    vector<int> ans = get2NonRepeatingNos(arr, n);
    
    cout << "The non-repeating elements are " << ans[0] << " and " << ans[1];

    return 0;
}
