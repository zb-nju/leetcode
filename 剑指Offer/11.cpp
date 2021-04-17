#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int func(const vector<int>& numbers, int l, int r){
        if(l==r)
            return numbers[l];
        int mid = (l+r)/2;
        if(numbers[mid]>numbers[r])
            return func(numbers, mid+1, r);
        else if(numbers[mid]<numbers[r])
            return func(numbers, l, mid);
        else
            return func(numbers,l,r-1);
    }
    int minArray(vector<int>& numbers) {
        return func(numbers, 0, numbers.size()-1);
    }
};

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        while(l<r){
            int mid = (l+r)/2;
            if(numbers[mid]<numbers[r])
                r = mid;
            else if(numbers[mid]>numbers[r])
                l = mid + 1;
            else
                r--;
        }
        return numbers[l];
    }
};