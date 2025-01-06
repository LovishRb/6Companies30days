class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int left = 0;
        int right = 0;

        long long  curr_sum = 0;
        long long ans=0;

        
        while(right < nums.size()){
            
            int element = nums[right];
            // right pointer wo check krega ki map mein exist krta hai ya nahi
            int exist_index = (mp.count(element) ? mp[element] : - 1);

            // if the index of the previous present element in map is greater than equal to left pointer which is the first element of the window than we need to remove beavuse of the distinct elements condition 
            while(right - left + 1 > k || left <= exist_index){
                curr_sum  -= nums[left];
                left++;
            }
            // else we will push the element into map and store its corresponding index;
            mp[element]  = right;
            curr_sum += nums[right];

            // now check that the size of the window is reached..
            if(right - left + 1 == k){
                ans = max(ans , curr_sum);
            }
            right++;


        }
        return ans;
    }
};