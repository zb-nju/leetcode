#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        unordered_map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(q.size()<k)
                q.emplace(*it);
            else{
                if(it->second>q.top().second){
                    q.pop();
                    q.emplace(*it);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};