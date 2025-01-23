class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int max_len = -1;
        unordered_map<int,int> mp;
        for(int right= 0 ; right < nums.size();right++){
            mp[nums[right]]++;

            while(mp[nums[right]] > k){
                mp[nums[left]]--;

                if(mp[nums[left]] == 0)mp.erase(nums[left]);

                left++;
            }
            max_len = max(max_len,right-left+1);
        }

        return max_len;
    }
};