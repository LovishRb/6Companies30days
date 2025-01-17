class Solution {
public:

    bool solve(string s , int index, unordered_map<string,int> mp,int n,vector<int>& dp ){
        if(index == n)return true;

        string temp="";

        if(dp[index] !=-1)return dp[index];
        for(int i =index ; i<n;i++){
            temp += s[i];
            if(mp.find(temp) != mp.end()){
                if(solve(s,i+1,mp,n,dp))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;

         vector<int> dp(s.size(), -1);

        for(string s : wordDict)mp[s]++;

        return solve(s,0,mp,s.size(),dp);
    }
};