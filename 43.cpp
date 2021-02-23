/*
 * @Author: your name
 * @Date: 2020-08-13 23:18:47
 * @LastEditTime: 2020-08-14 08:01:06
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\43.cpp
 */
#include<iostream>
#include<string>
using namespace std;

// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         reverse(num1.begin(),num1.end());
//         reverse(num2.begin(),num2.end());
//         int n1=num1.size(),n2=num2.size(),i=0,c=0,t;
//         string ans;
//         while(i<n1&&i<n2){
//             t=num1[i]+num2[i]-2*'0'+c;
//             c=t>=10?1:0;
//             num1[i]=t+'0'-10*c;
//             i++;
//         }
//         while(i<n1){
//             t=num1[i]+c-'0';
//             c=t>=10?1:0;
//             num1[i]=t+'0'-10*c;
//             i++;
//         }
//         while(i<n2){
//             t=num2[i]+c-'0';
//             c=t>=10?1:0;
//             num1+=(t+'0'-10*c);
//             i++;
//         }
//         if(c)
//             num1+='1';
//         reverse(num1.begin(),num1.end());
//         return num1;
//     }

//     string multiply(string num1, string num2) {
//         if(num1=="0"||num2=="0")
//             return "0";
//         string ans="0";
//         for(int i=0;i<num2.size();i++){
//             string t="";
//             int c=0,t2=0,now=num2[i]-'0';
//             for(int j=num1.size()-1;j>=0;j--){
//                 t2=now*(num1[j]-'0')+c;
//                 t+=(t2%10+'0');
//                 c=t2/10;
//             }
//             reverse(t.begin(),t.end());
//             ans=addStrings(ans,t);
//             num1+='0';
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int m=num1.size(),n=num2.size(),s=m+n;
        int*arr=new int[m+n];
        string ans="";
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                arr[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0;i<s-1;i++){
            arr[i+1]+=arr[i]/10;
            arr[i]%=10;
            ans+=arr[i]-'0';
        }
        ans+=arr[s-1]-'0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};