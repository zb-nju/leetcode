#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n));
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l - 1 <n; i++){
                int j = i + l - 1;
                if(l == 1)
                    dp[i][j] = true;
                else if(l == 2)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                if(dp[i][j] && l > ans.size())
                    ans = s.substr(i, l);
            }
        }
        return ans;
    }
};

class Solution {
public:
    pair<int, int> expand(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        left++; right--;
        return {left, right};
    }
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 0;
        for(int i = 0; i < n; i++){
            auto a = expand(s, i, i);
            auto b = expand(s, i, i + 1);
            if(a.second - a.first > end - start){
                start = a.first;
                end = a.second;
            }
            if(b.second - b.first > end - start){
                start = b.first;
                end = b.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};