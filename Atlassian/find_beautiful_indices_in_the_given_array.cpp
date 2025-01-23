class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        if (a.empty() || b.empty() || k < 0 || s.size() < max(a.size(), b.size())) {
            return {}; 
        }

        vector<int> v1, v2;
        int n = s.size();

        
        for (int i = 0; i <= n - a.size(); i++) {
            if (s.substr(i, a.size()) == a) {
                v1.push_back(i);
            }
        }

        
        for (int i = 0; i <= n - b.size(); i++) {
            if (s.substr(i, b.size()) == b) {
                v2.push_back(i);
            }
        }

        
        vector<int> ans;
        for (int num : v1) {
            for (int j = 0; j < v2.size(); j++) {
                if (abs(num - v2[j]) <= k) {
                    ans.push_back(num);
                    break; 
                }
            }
        }
        return ans;
    }
};