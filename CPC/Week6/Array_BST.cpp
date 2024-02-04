#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> preorder;
        constructBST(nums, 0, nums.size() - 1, preorder);
        return preorder;
    }
    
    void constructBST(vector<int>& nums, int left, int right, vector<int>& preorder) {
        if (left > right) return;
        int mid = left + (right - left) / 2;
        preorder.push_back(nums[mid]);
        constructBST(nums, left, mid - 1, preorder);
        constructBST(nums, mid + 1, right, preorder);
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.sortedArrayToBST(nums);
        for(auto i: ans)
            cout << i <<" ";
        cout << "\n";
    }
    return 0;
}
