class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        
        if (n < 3) return 0;

        int left = 0;

        while (left < n - 1) {
            int right = left;

            
            if (right + 1 < n && arr[right] < arr[right + 1]) {
                while (right + 1 < n && arr[right] < arr[right + 1]) right++;
            }

            // If there's no peak or no descending part, continue
            if (right == left || right + 1 == n || arr[right] <= arr[right + 1]) {
                left = right + 1;
                continue;
            }

            
            while (right + 1 < n && arr[right] > arr[right + 1]) right++;

            
            ans = max(ans, right - left + 1);
            
            left = right;
        }

        return ans;
    }
};
