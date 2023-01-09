class Solution {
public:
    int M=1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
     //dp[i]=number of ppl who know secret on ith day
        int share = 0;
        int ans = 0;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            dp[i]= (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + M) % M;
            share=dp[i];
        }
        for (int i = n - forget + 1; i <= n; ++i)
            ans = (ans + dp[i]) % M;
        return ans;
    }
};