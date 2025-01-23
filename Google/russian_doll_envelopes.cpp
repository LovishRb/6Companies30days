class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),cmp);

        vector<int> lis;
        
        for(int i = 0;i<envelopes.size();i++){
            int element = envelopes[i][1];
            
            int index = lower_bound(lis.begin(), lis.end(), element) - lis.begin();
            
            if(index >= lis.size()) lis.push_back(element);
            else lis[index] = element;
        }
        
        return lis.size();
    }
};