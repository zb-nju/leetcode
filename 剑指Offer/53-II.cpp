#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] == mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return nums[mid] == mid? mid+1:mid;
    }
};