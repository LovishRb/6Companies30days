class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int left =0;
        int right = 0;
        vector<int> ans;
        queue<int> q;
        int maxi = 0;
        while(right < arr.size()){
            int curr_element = arr[right];
            q.push(curr_element);
            maxi = max(maxi,curr_element);
            
            
            
            if (right - left + 1 == k) {
                ans.push_back(maxi);
                
                if(arr[left] == maxi) {
                    q.pop();
                    // again calculate the maximum for the new window
                    maxi = INT_MIN;
                    queue<int> temp = q; 
                    while (!temp.empty()) {
                        maxi = max(maxi, temp.front());
                        temp.pop();
                    }
                } 
                else {
                    q.pop();
                }
                left++; 
            }
            
            right++;
            
        }
        
        return ans;
    }
};