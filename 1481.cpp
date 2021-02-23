/*
 * @Author: your name
 * @Date: 2020-07-11 23:35:18
 * @LastEditTime: 2020-07-12 00:33:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1481.cpp
 */ 

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         map<int,int> mymap;
//         vector<int>::iterator pv;
//         map<int,int>::iterator pm;
//         priority_queue<int,vector<int>,greater<int>>myq;
//         for(pv=arr.begin();pv!=arr.end();pv++)
//             mymap[*pv]++;
//         for(pm=mymap.begin();pm!=mymap.end();pm++)
//             myq.push(pm->second);
//         while(k>0 && k>=myq.top()){
//             k-=myq.top();
//             myq.pop();
//         }
//         return myq.size();
//     }
// };

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mymap;
        vector<int>::iterator pv;
        unordered_map<int,int>::iterator pm;
        vector<int> myvec;
        for(pv=arr.begin();pv!=arr.end();pv++)
            mymap[*pv]++;
        for(pm=mymap.begin();pm!=mymap.end();pm++)
            myvec.push_back(pm->second);
        sort(myvec.begin(),myvec.end());
        int ans=myvec.size();
        for(pv=myvec.begin();pv!=myvec.end();pv++){
            if(*pv>k)
                break;
            k-=*pv;
            ans--;
        }
        return ans;
    }
};

int main()
{
    vector<int>arr;
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(4);
    Solution s;
    cout<<s.findLeastNumOfUniqueInts(arr,1);
    return 0;
}
