#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int>ans;
        for(int i=0;i<len;i++)
        {
            int t=nums[i];
            for(int j=i+1;j<len;j++)
            {
                if(t+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int> ans;
        map<int,int> mymap;
        for(int i=0;i<len;i++)
        {
            map<int ,int >::iterator l_it;
            l_it=mymap.find(target-nums[i]);
            if(l_it!=mymap.end())
            {
                ans.push_back(l_it->second);
                ans.push_back(i);
                break;
            }
            mymap[nums[i]]=i;
        }
        return ans;
    }
};