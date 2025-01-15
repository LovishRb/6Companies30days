class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int distanceValue = 0;
        sort(arr2.begin(), arr2.end());
        
        for (int i = 0; i < arr1.size(); i++) {
            int a = arr1[i];
            bool cnt = true;
            
            int l = 0;
            int r = arr2.size() - 1;
            int m = -1;
            
            while (l <= r) {
                m = l + (r - l) / 2;
                int b = arr2[m];
                if (abs(b - a) <= d) {
                    cnt = false;
                    break;
                }
                else if (b> a)
                    r = m - 1;
                else
                    l = m + 1;
            }
            
            if (cnt)
                distanceValue++;
        }
        
        return distanceValue;
    }
};