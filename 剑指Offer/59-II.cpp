#include<iostream>
#include<queue>
using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        if(!maxQ.empty())
            return maxQ.front();
        else
            return -1;
    }

    void push_back(int value) {
        while(!maxQ.empty() && value > maxQ.back())
            maxQ.pop_back();
        maxQ.push_back(value);
        numsQ.push_back(value);
    }

    int pop_front() {
        if(numsQ.empty())
            return -1;
        if(maxQ.front() == numsQ.front())
            maxQ.pop_front();
        int res = numsQ.front();
        numsQ.pop_front();
        return res;
    }

private:
    deque<int> numsQ;
    deque<int> maxQ;
};