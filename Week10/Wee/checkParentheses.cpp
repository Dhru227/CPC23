#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(const std::string& str) {
    std::stack<char> s;
    for (char c : str) {
        if (c == '(') {
            s.push('(');
        } else if (c == ')') {
            if (s.empty()) {
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.empty();
}

int main() {
    std::string str = "()(())()";
    if (checkParentheses(str)) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Not Balanced" << std::endl;
    }
    return 0;
}
