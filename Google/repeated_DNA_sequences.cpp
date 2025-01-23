class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mp;

        
        for(int i =0;i+10<=s.length() ;i++){
            mp[s.substr(i,10)]++;
        }

        for(auto it : mp){
            if(it.second > 1)
                v.push_back(it.first);
        }

        return v;
    }
};