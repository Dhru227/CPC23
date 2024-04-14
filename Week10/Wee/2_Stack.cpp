#include <iostream>
#include <vector>

class TwoStacks {
    std::vector<int> arr;
    int top1, top2;
public:
    TwoStacks(int n) : arr(n), top1(-1), top2(n) {}

    void push1(int x) {
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        } else {
            std::cout << "Stack Overflow by element: " << x << std::endl;
        }
    }

    void push2(int x) {
        if (top2 - 1 > top1) {
            arr[--top2] = x;
        } else {
            std::cout << "Stack Overflow by element: " << x << std::endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
    }

    int pop2() {
        if (top2 < arr.size()) {
            return arr[top2++];
        } else {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
    }
};

int main() {
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    std::cout << "Popped element from stack1 is: " << ts.pop1() << std::endl;
    ts.push2(40);
    std::cout << "Popped element from stack2 is: " << ts.pop2() << std::endl;
    return 0;
}
