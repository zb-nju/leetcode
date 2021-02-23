#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         nums.erase(unique(nums.begin(),nums.end()),nums.end());
//         return nums.size();
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),x=0;
        for(int i=0;i<n;i++)
            if(nums[i]!=nums[x])
                nums[++x]=nums[i];
        return n==0?0:++x;
    }
};