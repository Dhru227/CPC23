#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top(); 
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;        
    }
};

int main() {
    Solution solution;
    
    std::vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    std::vector<int> result1 = solution.dailyTemperatures(temperatures1);
    std::cout << "Output for temperatures1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> temperatures2 = {30,40,50,60};
    std::vector<int> result2 = solution.dailyTemperatures(temperatures2);
    std::cout << "Output for temperatures2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> temperatures3 = {30,60,90};
    std::vector<int> result3 = solution.dailyTemperatures(temperatures3);
    std::cout << "Output for temperatures3: ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
