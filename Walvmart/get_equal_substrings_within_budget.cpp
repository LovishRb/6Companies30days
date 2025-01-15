class Solution {
public:
    
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for(int i =0;i<s.size();i++){
            int dif = abs(t[i]-s[i]);
            diff.push_back(dif);
        }

        int left = 0;
        int maxi=0;
        int cost =0;
        int right = 0;
        while (right < s.size()) {
        cost += diff[right]; /

        
            while (cost > maxCost) {
                cost -= diff[left];
                left++;
            }

            
            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;

    }
};