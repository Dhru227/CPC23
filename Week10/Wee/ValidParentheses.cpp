#include <iostream>
#include <stack>
#include <string>

int minParentheses(const std::string& p) {
    std::stack<int> stk;
    int ans = 0;

    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '(') {
            stk.push(i);
        } else {
            if (!stk.empty()) {
                stk.pop();
            } else {
                ans += 1;
            }
        }
    }

    ans += stk.size();

    return ans;
}

int main() {
    std::string p = "())";
    std::cout << minParentheses(p) << std::endl;

    return 0;
}
