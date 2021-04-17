#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for(auto &n:nums)
            res ^= n;
        int div = 1;
        while((div&res) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for(auto &n:nums){
            if(n&div)
                a^=n;
            else
                b^=n;
        }
        return vector<int>({a, b});
    }
};