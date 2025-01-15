class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        set<pair<int,int>> s;

        for(int i =0;i<nums.size()-1;i++){
            int j =nums.size()-1;
            while(i<j){
                if(abs(nums[i]-nums[j]) == k){
                    s.insert({nums[i],nums[j]});
                    j--;
                }
                else if(abs(nums[i]-nums[j])> k)j--;
                else{
                    break;
                }
            }
        }
        return s.size();
    }
};