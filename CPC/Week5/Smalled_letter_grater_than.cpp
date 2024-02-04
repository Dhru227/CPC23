#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        char ans = l[0];
        int diff = INT_MAX;
        for (int i = 0; i < l.size(); i++) {
            int currdiff = (l[i] + '0') - (target + '0');
            if (l[i] > target and currdiff < diff) {
                diff = currdiff;
                ans = l[i];
            }
        }
        return ans;
    }
};

int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    Solution obj;
    char result = obj.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after " << target << " is: " << result << endl;
    return 0;
}
