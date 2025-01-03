class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n= nums.size();

        // sort decreasingly
        priority_queue<int> q(nums.begin(),nums.end());

        int j =0;

        for(int i =1;i<n;i+=2){
            nums[i] = q.top();
            q.pop();
        }
        
        for(int i =0;i<n;i+=2){
            nums[i] = q.top();
            q.pop();
        }
        
    }
};