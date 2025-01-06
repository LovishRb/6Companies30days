class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char ,int> mp;

        for(char c : s)mp[c]++;

        int i =0;
        while(i<s.size()){
            if(mp[s[i]] == 1){
                return i;
            }
            i++;
        }
        return -1;
    }
};