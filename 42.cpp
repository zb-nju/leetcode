#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len < 3) return 0;
        int left = 0, right = len - 1, leftMax = height[left], rightMax = height[right], ans = 0;
        while(left < right){
            if(leftMax < rightMax){
                if(height[left] > leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            }else{
                if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};