class KthLargest {
public:
    vector<int> v1;int k ;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            v1.push_back(num);
        }
        sort(v1.begin(),v1.end());
    }

    
    int add(int val) {
        auto index  = lower_bound(v1.begin(),v1.end(),val);
        v1.insert(index , val);
        return v1[v1.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */