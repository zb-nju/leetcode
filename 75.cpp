#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end0=0,begin2=nums.size()-1,i=0,t;
        while(i<begin2){
            if(nums[i]==0){
                t=nums[end0];
                nums[end0]=0;
                nums[i]=t;
                end0++;
                i++;
            }
            else if(nums[i]==2){
                t=nums[begin2];
                nums[begin2]=2;
                nums[i]=t;
                begin2--;
            }
            else
            {
                i++;
            }
        }
        return;
    }
};