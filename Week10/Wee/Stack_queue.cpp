#include <iostream>
#include <queue>

class Stack {
    std::queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty())
            return;
        q1.pop();
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() { return q1.size(); }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "current size: " << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    std::cout << "current size: " << s.size() << std::endl;
    return 0;
}
