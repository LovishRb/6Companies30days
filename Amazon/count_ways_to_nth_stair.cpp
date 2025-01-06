class Solution {
public:
    int solve(int index ,int jump,bool is_possible,int k,unordered_map<string,int>& mp){
        int ans =0;
        string temp = to_string(index) + to_string(jump) + to_string(is_possible);
        // base case
        if(index > k+1)return 0;

        if(index == k)ans++;

        if(mp.find(temp) != mp.end())return mp[temp];
        
        if(is_possible)
            ans  += solve(index - 1,jump,false,k,mp);

        ans += solve(index + pow(2,jump),jump+1,true,k,mp);

        return mp[temp]=ans;

    }
    int waysToReachStair(int k) {
        unordered_map<string,int> mp;
        return solve(1,0,true,k,mp);
    }
};