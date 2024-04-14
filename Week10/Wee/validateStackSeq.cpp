#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> s;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

int main() {
    Solution sol;
    std::vector<int> pushed1 = {1, 2, 3, 4, 5};
    std::vector<int> popped1 = {4, 5, 3, 2, 1};
    std::cout << "Output for pushed1 and popped1: " << std::boolalpha << sol.validateStackSequences(pushed1, popped1) << std::endl;

    std::vector<int> pushed2 = {1, 2, 3, 4, 5};
    std::vector<int> popped2 = {4, 3, 5, 1, 2};
    std::cout << "Output for pushed2 and popped2: " << std::boolalpha << sol.validateStackSequences(pushed2, popped2) << std::endl;

    return 0;
}
