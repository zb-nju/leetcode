#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zero = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(nums[i++] == 0) zero++;
        for(; i < 5; i++){
            if(i > 0 && nums[i - 1] != 0){
                if(nums[i] == nums[i - 1])
                    return false;
                zero -= (nums[i] - nums[i - 1] - 1);
                if(zero < 0)
                    return false;
            }
        }
        return true;
    }
};