#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for(auto &c: s){
            if(c == ' ')
                ans += "%20";
            else
                ans += c;
        }
        return ans;
    }
};