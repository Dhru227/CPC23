#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};

int main() {
    Solution solution;

    string columnTitle;
    cout << "Enter Excel column title: ";
    cin >> columnTitle;

    int columnNumber = solution.titleToNumber(columnTitle);
    cout << "Corresponding column number: " << columnNumber << endl;

    return 0;
}
