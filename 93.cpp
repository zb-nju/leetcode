#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        string cur=s;
        func(s.size(),0,-1,s,cur);
        return ans;
    }

    void func(int n,int now,int last,string& s,string cur){
        if(now==3){
            if(valid(cur,last+1,n-1))
                ans.push_back(cur);
            return;
        }
        for(int i=last+1;i<n&&i<last+4;i++){
            if(valid(cur,last+1,i)){
                cur.insert(cur.begin()+i+1,'.');
                func(n+1,now+1,i+1,cur,s);
                cur.erase(i+1,1);
            }
        }

    }

    bool valid(string&s,int l,int r){
        int t=0;
        for(int i=l;i<=r;i++){
            if(l!=r&&s[l]=='0')
                return false;
            t=t*10+s[i]-'0';
            if(t>255)
                return false;
        }
        return true;
    }
};