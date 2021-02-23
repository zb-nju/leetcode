#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>=target)
                r=mid-1;
            else
                l=mid+1;
        }
        if(nums[l]<target)
            return l;
        else
            return l+1;
    }
};