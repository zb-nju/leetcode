#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        for(auto n:nums){
            for(int i = 0; i < 32; i++){
                count[i] += (n&1);
                n >>= 1;
            }
        }
        int res = 0;
        for(int i = 31; i >= 0; i--){
            res <<= 1;
            res |= (count[i] % 3);
        }
        return res;
    }
};