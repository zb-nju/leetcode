#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> b(nums.size(), false);
        for(auto n:nums){
            if(b[n])
                return n;
            b[n] = true;
        }
        return -1;
    }
};