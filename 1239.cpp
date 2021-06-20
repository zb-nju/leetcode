#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        for(string &s:arr){
            int t = calculateMask(s);
            if(t > 0){
                masks.push_back(calculateMask(s));
                sizes.push_back(s.size());
            }
        }
        ans = 0;
        func(0, 0, 0);
        return ans;
    }

private:
    vector<int>masks;
    vector<int>sizes;
    int ans;

    void func(int i, int mask, int now){
        if(i >= masks.size()){
            if(now > ans)
                ans = now;
            return;
        }
        if((mask & masks[i]) == 0)
            func(i + 1, mask | masks[i], now + sizes[i]);
        func(i + 1, mask, now);
    }

    inline int calculateMask(string input){
        int ret = 0, t;
        for(char &c:input){
            t = 1<<(c-'a');
            if((ret & t) != 0)
                return 0;
            ret += t;
        }
        return ret;
    }
};