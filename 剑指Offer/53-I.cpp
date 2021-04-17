#include<iostream>
#include<vector>
using namespace static

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size(), mid;
        while(l < r){
            mid = (l + r) / 2;
            if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
            else break;
        }
        int ans = 0, i = mid;
        while(i < nums.size() && nums[i] == target){
            ans++;i++;
        }
        i = mid - 1;
        while(i >= 0 && nums[i] == target){
            ans++;i--;
        }
        return ans;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int right = l;
        if(r >= 0 && nums[r] != target) return 0;
        l = 0; r = nums.size() - 1;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int left = r;
        return right - left - 1;
    }
};