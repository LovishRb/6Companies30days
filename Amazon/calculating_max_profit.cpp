class Solution {
public:
    int solve(int index ,bool is_pos_to_buy,int k,vector<int>& prices,unordered_map<string,int> &mp){
        // base case 
        if(index == prices.size() || k==0)
            return 0;
        

        // we can us this map trick but it may fail in some cases so it is recommended to use3d dp vector
string str = to_string(index) + "-" + to_string(is_pos_to_buy) + "-" + to_string(k);

        if(mp.find(str) != mp.end()){
            return mp[str];
        }

        // if(dp[index][is_pos_to_buy][k] != -1) return dp[index][is_pos_to_buy][k];

        int ans =0;
        if(is_pos_to_buy){
            // buy kr skte

            int take = -prices[index] + solve(index+1,false,k,prices,mp);
            int not_take = solve(index + 1,true,k,prices,mp);
            ans = max (take,not_take);
        }
        else{
            // sell
            int take = prices[index] + solve(index+1,true,k-1,prices,mp);
            int not_take = solve(index + 1,false,k,prices,mp);
            ans = max (take,not_take);
        }
        return mp[str]=ans;
        // return dp[index][is_pos_to_buy][k]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        unordered_map<string,int> mp;
        
        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int> (k+1,-1)));
        return solve(0,true,k,prices,mp);
    }
};