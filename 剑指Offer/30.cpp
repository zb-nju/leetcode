#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if(mins.empty()||x<=mins.top())
            mins.push(x);
    }

    void pop() {
        if(s.top()==mins.top())
            mins.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return mins.top();
    }
private:
    stack<int> s;
    stack<int> mins;
};