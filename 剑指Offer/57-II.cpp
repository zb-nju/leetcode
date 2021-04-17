#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l = 1, r = 1;
        vector<vector<int>> ans;
        while(r < target){
            int sum = (l + r - 1) * (r - l) / 2;
            if(sum > target)
                l++;
            else if(sum < target)
                r++;
            else{
                vector<int> temp;
                for(int i = l; i < r; i++)
                    temp.push_back(i);
                ans.push_back(temp);
                l++;
            }
        }
        return ans;
    }

};