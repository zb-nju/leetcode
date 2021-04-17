#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k || k <= 0)
            return {};
        int low = 1 - k, high = 0;
        vector<int> ans;
        deque<int> dq;
        while(high < n){
            if(low >= 1 && nums[low - 1] == dq.front())
                dq.pop_front();

            while(!dq.empty() && nums[high] > dq.back())
                dq.pop_back();
            dq.push_back(nums[high]);

            if(low >= 0)
                ans.push_back(dq.front());
            high++;
            low++;
        }
        return ans;
    }
};