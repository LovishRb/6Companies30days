class Solution {
public:
    int minMoves2(vector<int>& nums){

        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        int res =0;
        
        if(nums.size() % 2 == 0)
            res = (nums[mid-1] + nums[mid])/2;
        
        else
            res = nums[mid];
        
        int sum=0;
        for(int i =0;i<nums.size();i++)
            sum += abs(res - nums[i]);
        

        return sum;

    }
};