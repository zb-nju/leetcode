/*
 * @Author: zb-nju
 * @Date: 2020-10-14 10:14:06
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-14 10:43:42
 */
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char,int> ansmap;
        for(int i=0;i<A.size();i++){
            string t = A[i];
            map<char,int>newmap;
            for(int j=0;j<t.size();j++)
                newmap[t[j]]++;
            if(i==0)
                ansmap = newmap;
            else{
                for(int k=0;k<26;k++)
                    ansmap['a'+k]=min(ansmap['a'+k],newmap['a'+k]);
            }
        }
        vector<string> ans;
        for(int k=0;k<26;k++){
            while(ansmap['a'+k]){
                string t = "";
                t += 'a'+k;
                ans.push_back(t);
                ansmap['a'+k]--;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: A) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};