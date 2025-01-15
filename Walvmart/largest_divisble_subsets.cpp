class Solution {
public:
    vector<int> prev;
    void solve(int index,vector<int>& nums,vector<int>& ans,vector<int>& dp){
        // base case

        if(index >= nums.size()){
           // to ensure it contains the largest valid subset we found
            if(ans.size() > prev.size()) prev=ans;
            return;
        }
        bool cond = ans.size() == 0 || nums[index] % ans.back() == 0;

        // if the bigger size already exist store... it in the dp vector
        if(cond && dp[index] < (int)ans.size() + 1 ){
            // pick kr skte hai 
            dp[index] = ans.size() + 1;
            ans.push_back(nums[index]);
            solve(index+1,nums,ans,dp);

            // ya nhi pick krna
            ans.pop_back();
        }
        // we cannot pick as cond is false...
        solve(index+1,nums,ans,dp);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;

        vector<int> dp(nums.size(),-1);

        sort(nums.begin(),nums.end());
        solve(0,nums,ans,dp);
        return prev;

    }
};