#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0,start,l,r;
        while(i<n){
            start = i;
            while(i<n&&s[i]!=' ')
                i++;
            l=start;r=i-1;
            while(l<r)
                swap(s[l++],s[r--]);
            while(i<n&&s[i]==' ')
                i++;
        }
        return s;
    }
};