class Solution {
  public:
    pair<string,int> solve(vector<int>& arr , int start_index,int end_index,vector<vector<pair<string,int>>>&  dp){
        
        
        // base case
        if(start_index == end_index)
        {
            string temp = "";
            temp += char('A' + start_index-1);
            return {temp, 0};
        }
        
        if(dp[start_index][end_index].first != ""){
            return dp[start_index][end_index];
        }
        
        int ans = INT_MAX;
        string str;
        
        for(int k =start_index ; k<end_index;++k){
            pair<string,int> cost1 = solve(arr,start_index,k,dp);
            pair<string,int> cost2 = solve(arr,k+1,end_index,dp);
            int cost3 = arr[start_index-1] * arr[k] * arr[end_index];
            
            int curr_cost = cost1.second + cost2.second + cost3;
            
            if(curr_cost < ans){
                ans = curr_cost;
                str  = "(" + cost1.first + cost2.first + ")";
            }
            
        
        }
            
        return dp[start_index][end_index]={str,ans};    
        
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        // cout<<solve(arr,1,arr.size()-1).first<<endl;
        vector<vector<pair<string,int>>>  dp(arr.size(),vector<pair<string,int>>(arr.size(),{"",-1}));
        return solve(arr,1,arr.size()-1,dp).first;
    }
};