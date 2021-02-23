#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> num1(10,0);
        vector<int> num2(10,0);
        int A=0,B=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                A++;
            else{
                num1[secret[i]-'0']++;
                num2[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
            B+=min(num1[i],num2[i]);
        string ans="";
        ans+=(char)(A+'0')+"A"+(char)(B+'0')+"B";
        return ans;
    }
};