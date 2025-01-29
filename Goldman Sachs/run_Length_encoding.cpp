class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int a,b;
        
        vector<int> freq(arr.size()+1,0);
        
        for(int num : arr){
            freq[num]++;
        }
        
        for(int i = 1;i<freq.size();++i){
            if(freq[i] == 2)a=i;
            if(freq[i] == 0)b=i;
        }
        
        return {a,b};
        
    }
};