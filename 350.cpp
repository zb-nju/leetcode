/*
 * @Author: your name
 * @Date: 2020-07-13 17:26:13
 * @LastEditTime: 2020-07-13 17:26:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\350.cpp
 */ 
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        vector<int>ans;
        while(i<n&&j<m){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i]>nums2[j])
                j++;
            else
                i++;
        }
        return ans;
//     }
// };

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,int> mymap;
        int t;
        for(int i=0;i<nums1.size();i++)
            mymap[nums1[i]]++;
        for(int i=0;i<nums2.size();i++){
            t=nums2[i];
            if(mymap[t]>0){
                ans.push_back(t);
                mymap[t]--;
            }
        }
        return ans;
    }
};