class Solution {
public:
    int binarySearch(string s, const string& suff, int i) {
        int si = 0;
        int ei = i;
        int maxlen = 0;

        while (si <= ei) {
            int mid = si + (ei - si) / 2;

            // Check if `suff` starts with `lst[mid].inc`
            if (suff.compare(0, mid + 1, s, 0, mid + 1) == 0) { 
                maxlen = max(maxlen, mid+1);
                si = mid + 1;
            } else {
                ei = mid - 1;
            }
        }
        return maxlen;
    }

    // Function to calculate the sum of scores
    long long sumScores(const string& s) {
        long long sum = 0;
        int n = s.length();

        // Process each pair
        for (int i = 0; i < s.size(); ++i) {
            
            const string& suff = s.substr(i);

            if (s.substr(0,n-i) == suff) {
                sum += n-i;
            } else {
                // Perform binary search
                int maxlen = binarySearch(s, suff, n-i-1);
                sum += maxlen;
            }
        }
        return sum;
    }
};