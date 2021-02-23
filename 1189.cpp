/*
 * @Author: your name
 * @Date: 2020-07-07 08:45:25
 * @LastEditTime: 2020-07-07 08:45:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1189.cpp
 */ 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int num[5]={0,0,0,0,0};
        for(int i=0;i<text.size();i++){
            switch (text[i])
            {
            case 'a':
                num[0]++;
                break;
            case 'b':
                num[1]++;
                break;
            case 'l':
                num[2]++;
                break;
            case 'o':
                num[3]++;
                break;
            case 'n':
                num[4]++;
                break;
            default:
                break;
            }
        }
        num[2]/=2;num[3]/=2;
        int ans = num[0];
        for(int i=1;i<5;i++)
            if(ans>num[i])
                ans = num[i];
        return ans;
    }
};