class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch : s)mp[ch]++;

        vector<pair<int,char>> ans;

        for(auto [ch , freq] : mp){
            ans.push_back({freq,ch});
        }

        sort(ans.rbegin(),ans.rend());

        string temp ;

        for(auto [freq,ch] : ans){
            temp.append(freq,ch);
        }
        
        return temp;

    }
};