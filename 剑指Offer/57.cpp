#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, t;
        while(l < r){
            t = nums[l] + nums[r];
            if(t > target)
                r--;
            else if(t < target)
                l++;
            else
                break;
        }
        return {nums[l], nums[r]};
    }
};