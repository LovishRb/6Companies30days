class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;

        for(int i =0;i<nums.size();++i){
            vector<int> res;
            int count=0;
            for(int j =i;j<nums.size();j++){
                res.push_back(nums[j]);
                if(nums[j] % p ==0){
                    count+=1;
                }
                if(count > k)
                    break;
                
                ans.insert(res);
            }
        }
        return ans.size();
    }
};