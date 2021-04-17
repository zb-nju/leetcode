#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return func(postorder, 0, postorder.size()-1);
    }

    bool func(const vector<int>& postorder, int l, int r){
        if(r <= l)
            return true;
        int rootVal = postorder[r];
        int i = l;
        while(postorder[i] < postorder[r])
            i++;
        int j = i;
        while(postorder[j] > postorder[r])
            j++;
        return j == r && func(postorder, l, i - 1) && func(postorder, i, r - 1);
    }
};