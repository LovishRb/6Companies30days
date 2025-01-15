class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq;
        for(int i =0;i<nums.size();++i){
            pq.push({nums[i],i});
        }
        vector<int> index;
        while(k!=0 && !pq.empty()){
            int x = pq.top().second;
            pq.pop();
            index.push_back(x);
            k--;
        }
        sort(index.begin(),index.end());
        vector<int> ans;
        for(int i : index){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};