#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        func(candidates,target,0,0);
        return ans;
    }
    void func(vector<int>&candidates,int target,int now,int begin){
        if(now==target){
            ans.push_back(t);
            return;
        }
        else
        {
            for(int i=begin;i<candidates.size();i++){
                if(now+candidates[i]<=target){
                    t.push_back(candidates[i]);
                    func(candidates,target,now+candidates[i],i);
                    t.pop_back();
                }
            }
        }
    }
};