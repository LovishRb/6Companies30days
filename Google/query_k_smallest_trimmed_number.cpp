class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

        vector<int> ans;
        int index1=0;
        for(vector<int>& query : queries){
            int k = query[0];
            int digits_at_right = query[1];
            vector<pair<string,int>> v;
            int index =0;
            for(string num : nums){
                // trim to digits_at right
                
                string trimmed = num.substr(num.size()-digits_at_right,digits_at_right);
                v.push_back({trimmed,index++});

            }
                sort(v.begin(),v.end());

            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};