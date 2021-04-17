class Solution{
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        else{
            long ans = 1;
            while(n>=3){
                if(n == 4){
                    ans = ans * 4 % 1000000007;
                    n -= 4;
                    break;
                }else{
                    ans = ans * 3 % 1000000007;
                    n -= 3;
                }
            }
            if(n)
                ans = ans * n % 1000000007;
            return ans;
        }
    }
};