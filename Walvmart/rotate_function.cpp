class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum =0;
        long long fn=0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            fn += i * nums[i];
        }
        long long maxi =INT_MIN;
        long long ans =0;
        cout<<fn<<endl;
        int right = nums.size()-1;
        int n = nums.size();
        if(n==1)return 0;
        int i = 0;
        while(i<n){
            // if(i==0){
            //     maxi = max(ans,fn);
            // }
            ans = sum + fn - nums[right--]*n;
            cout<<ans<<endl;
            maxi = max(ans,maxi);
            fn=ans;
            ans=0;
            i++;
        }

        return maxi;
    }
};