#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            
            if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr);
    if (peakIndex != -1) {
        cout << "Peak index in the mountain array: " << peakIndex << endl;
    } else {
        cout << "No peak index found in the mountain array." << endl;
    }
    return 0;
}
