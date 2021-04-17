#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
    stack<int>s1;
    stack<int>s2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        s2.push(value);
    }

    int deleteHead() {
        int ans = -1;
        if(!s1.empty()){
            ans = s1.top();
            s1.pop();
            return ans;
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()){
            ans = s1.top();
            s1.pop();
        }
        return ans;
    }
};