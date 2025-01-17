class Solution {
public:
    int solve(int left ,unordered_set<string> st , string s,vector<int>& dp){
        if(left == s.size())return 0;

        if(dp[left] != -1)return dp[left];
        // extra charcter
        int ans = solve(left+1,st,s,dp) + 1;
        // extra char nahi hai toh 
        for(int right = left ; right < s.size();++right){
            auto curr_str = s.substr(left,right-left+1);
            if(st.find(curr_str) != st.end())ans = min(ans,solve(right+1,st,s,dp));
        }

        return dp[left]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(s.size()+1,-1);
        return solve(0,st,s,dp);
    }
};