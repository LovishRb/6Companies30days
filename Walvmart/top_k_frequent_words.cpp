
class Solution {
public:
    static bool cmp(pair<string,int>& p1, pair<string,int>& p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }

        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        // map
        unordered_map<string,int> mp;

        for(string wrd : words)mp[wrd]++;

        vector<pair<string,int>>  ans;

        for(auto [str,freq] : mp){
            ans.push_back({str,freq});
        }

        sort(ans.begin(),ans.end(),cmp);

        vector<string> res;
        int i =0;
        while(k--){
            res.push_back(ans[i++].first);
        }
        return res;
    }
};