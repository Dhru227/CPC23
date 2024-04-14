#include <iostream>
#include <stack>
#include <deque>

class MyStack {
    std::stack<int> st;
    std::deque<int> dq;

public:
    void add(int data) {
        dq.push_back(data);
        if (dq.size() > st.size() + 1) {
            int temp = dq.front();
            dq.pop_front();
            st.push(temp);
        }
    }

    void pop() {
        if (dq.empty())
            return;

        int data = dq.back();
        dq.pop_back();
        if (st.size() > dq.size()) {
            int temp = st.top();
            st.pop();
            dq.push_front(temp);
        }
    }

    int getMiddleElement() {
        if (!dq.empty())
            return dq.front();
        else
            return -1; 
    }

    void deleteMiddleElement() {
        if (!dq.empty()) {
            dq.pop_front();
            if (st.size() > dq.size()) {
                int temp = st.top();
                st.pop();
                dq.push_front(temp);
            }
        }
    }
};

int main() {
    MyStack st;
    st.add(2);
    st.add(5);
    std::cout << "Middle Element: " << st.getMiddleElement() << std::endl;
    st.add(3);
    st.add(7);
    st.add(4);
    std::cout << "Middle Element: " << st.getMiddleElement() << std::endl;
    st.deleteMiddleElement();
    std::cout << "Middle Element: " << st.getMiddleElement() << std::endl;
    st.deleteMiddleElement();
    std::cout << "Middle Element: " << st.getMiddleElement() << std::endl;
    st.pop();
    st.pop();
    st.deleteMiddleElement();

    return 0;
}
