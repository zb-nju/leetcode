#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return ans;
    }

private:
    int ans;
    void mergeSort(vector<int> &nums, vector<int>& temp, int left, int right){
        if(left >= right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid + 1, right);
        merge(nums, temp, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right){
        int l = left, r = mid + 1, p = left;
        while(l <= mid && r <= right){
            if(nums[l] <= nums[r]){
                temp[p++] = nums[l++];
                ans += (r - mid - 1);
            }else{
                temp[p++] = nums[r++];
            }
        }
        while(l <= mid){
            temp[p++] = nums[l++];
            ans += (r - mid - 1);
        }
        while(r <= right){
            temp[p++] = nums[r++];
        }
        for(int i = left; i <= right; i++)
            nums[i] = temp[i];
    }
};