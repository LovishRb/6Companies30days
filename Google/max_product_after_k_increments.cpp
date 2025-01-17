class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9 + 7;

        long long ans =1;

        priority_queue<int , vector<int> , greater<int> > pq(nums.begin(),nums.end());

        while(k--){
            int x = pq.top() ;
            x = x + 1;
            pq.pop();
            pq.push(x);
        }

        while(!pq.empty()){
            ans = ((ans%mod) * (pq.top() % mod))%mod;
            pq.pop();
        }

        return ans;

    }
};