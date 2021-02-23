#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string dic[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    string t;

    vector<string> letterCombinations(string digits) {
        t="";
        if(digits.size()!=0)
            func(digits,0);
        return ans;
    }

    void func(string& digits,int now){
        if(now==digits.size()){
            ans.push_back(t);
            return;
        }
        string temp=dic[digits[now]-'2'];
        for(int i=0;i<temp.size();i++){
            t+=temp[i];
            func(digits,now+1);
            t.erase(t.begin()+now);
        }
    }
};