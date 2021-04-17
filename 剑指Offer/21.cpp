#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0,j = 0,temp = 0;
        while(j<nums.size()){
            if(nums[j] % 2 == 1){
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
            }
            j++;
        }
        return nums;
    }
};