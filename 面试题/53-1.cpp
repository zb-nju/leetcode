#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int ans=0;
//         vector<int>::iterator pn=find(nums.begin(),nums.end(),target);
//         for(;pn!=nums.end();pn++)
//         {
//             if(*pn==target)
//                 ans++;
//             else if(*pn>target)
//                 break;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upperbound(nums,target)-upperbound(nums,target-1);
    }
    int upperbound(vector<int>& nums, int target){
        int l=0,r=nums.size()-1,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return r;
    }
};