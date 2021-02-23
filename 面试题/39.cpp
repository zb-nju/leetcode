#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//16ms
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int> mymap;
//         int hsz=nums.size()/2;
//         vector<int>::iterator pn=nums.begin();
//         for(;pn!=nums.end();pn++)
//         {
//             mymap[*pn]++;
//             if(mymap[*pn]>hsz)
//                 break;
//         }
//         return *pn;
//     }
// };

// 28ms
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         return nums[nums.size()/2];
//     }
// };

// 摩尔投票法12ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==ans)
                count++;
            else
                count--;
            if(!count)
            {
                ans=nums[i];
                count++;
            }
        }
        return ans;
    }
};