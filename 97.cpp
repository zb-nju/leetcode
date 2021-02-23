#include<string>
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3)
            return false;
        vector<int>a(n2+1,false);
        a[0]=true;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                int p=i+j-1;
                if(i>0)
                    a[j]&=(s1[i-1]==s3[p]);
                if(j>0)
                    a[j]|=(a[j-1]&&s2[j-1]==s3[p]);
            }
        }
        return a[n2];
    }
};