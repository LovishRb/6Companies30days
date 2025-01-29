class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long lo = 1, hi = 1e10;
        long long ans = hi;
        long long lcm = (long long)d1 * d2 / gcd(d1, d2);

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long x = mid - mid / d1;
            long long y = mid - mid / d2;
            long long z = mid - mid / lcm;

            if (x < u1 || y < u2 || z < u1 + u2) {
                lo = mid + 1;
            } else {
                ans = min(ans, mid);
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};