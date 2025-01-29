class Solution {
public:
    int mod = 1e9 + 7;

    long solve(int start_day, int n, int delay, int forget,vector<int>& dp) {
        if (start_day > n) return 0;

        if(dp[start_day] != -1){
            return dp[start_day];
        }
        long ans = 1; 

        if (start_day + forget <= n) ans--;

        
        for (int i = start_day + delay; i < min(start_day + forget, n + 1); i++) {
            ans = (ans + solve(i, n, delay, forget,dp)) % mod;
        }

        return dp[start_day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(1001,-1);
        return solve(1,n,delay,forget,dp);
    }
};