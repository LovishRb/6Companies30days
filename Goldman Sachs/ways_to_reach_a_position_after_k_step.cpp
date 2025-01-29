class Solution {
public:
    int mod = 1e9 + 7;
    int solve( int startPos,int endPos,int k,vector<vector<int>>& dp){
        // base case    
        if(k<0)return 0;
        int ans =0;
        
        if(k == 0 ){
            if(startPos == endPos)return 1;
            return 0;
        }
        
        if(dp[startPos + 1000][k] != -1)return dp[startPos + 1000][k];

        // Move to left
        ans += (solve(startPos-1,endPos,k-1,dp)) % mod;
        // MOve to right
        ans+= solve(startPos+1,endPos,k-1,dp) % mod; 

        return dp[startPos + 1000][k]=ans % mod;  

    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(7001,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp);
    }
};