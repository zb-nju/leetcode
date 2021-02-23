#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<string>> G;
    vector<string> ans;

    void dfs(string s){
        sort(G[s].begin(),G[s].end());
        string now;
        while(!G[s].empty()){
            now=G[s][0];
            G[s].erase(G[s].begin());
            dfs(now);
        }
        ans.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<vector<string>>::iterator it;
        for(it=tickets.begin();it!=tickets.end();it++)
            G[(*it)[0]].emplace((*it)[1]);
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};