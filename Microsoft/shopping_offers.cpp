
class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& memo) {
        // Check if result is already memoized
        if (memo.find(needs) != memo.end()) {
            return memo[needs];
        }
        // finding the maximum ans 
        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += price[i] * needs[i];
        }

        
        for (vector<int>& v : special) {
            vector<int> new_needs = needs;
            bool valid_offer = true;

            for (int i = 0; i < needs.size(); i++) {
                if (new_needs[i] < v[i]) {
                    valid_offer = false;
                    break;
                }
                new_needs[i] -= v[i]; 
            }

            if (valid_offer) {
                ans = min(ans, v.back() + solve(price, special, new_needs, memo));
            }
        }

        
        memo[needs] = ans;
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        

        // dp array to store the needs array as well as result
        map<vector<int>, int> mp;  
        return solve(price,special,needs,mp);
    }
};