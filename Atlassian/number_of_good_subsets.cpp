const int MOD = 1e9 + 7;

int pow(int a, int b, int m) { // fast power method
    int ans = 1;
    while (b) {
        if (b & 1) ans = (ans * 1ll * a) % m;
        b /= 2;
        a = (a * 1ll * a) % m;
    }
    return ans;
}

class Solution {
    map <int, int> freq;
public:

// el is current element , going from 2 to 30
// pr is the product of the subset taken so far
// lets suppose a valid subset is { 6 , 7 , 11}
// Hence, count of such subsets => lans = freq[6] * freq[7] * freq[11]
// Time Complexity of solve `method` is not 2^30 as it is heavily pruned ( can be proved by, lets say subset is of size 17 so there must be 2 even numbers atleast , hence prime 2 is repeated twice in the product, hence maximum size of subset is 17, though it would be even smaller!

    int solve(int el, long long pr, int lans) {

        if (el > 30) {
            // pr == 1 implies empty subset , hence checking p > 1
            return (pr > 1) * lans;
        }

        int ans = solve(el + 1, pr, lans); // skipping el

        if (el % 4 and el % 9 and el % 25 and __gcd(el * 1ll, pr) == 1) {
            // taking el , __gcd(el * 1ll, pr) == 1 ensuring there is no common divisor of product of elements of subset taken so far and current el
            // Multiples of 4, 9, 25 can never be taken as they itself cant be represented as product of distinct primes
            ans += solve(el + 1, pr * el, lans * 1ll * freq[el] % MOD);
        }

        return ans % MOD;
    }

    int numberOfGoodSubsets(vector<int>& nums) {

        for (int el : nums) {
            freq[el]++;
        }

        // ans = ( countOfSubsets of elements from 2 to 30 )  * ( Number of possible subsets of ones)
        // Number of subsets of 1 are => 2^cntOfOnes ; Example => if frequency of 1 is 2 , number of subsets possible are {{},{1a},{1b} , {1a, 1b}}
        // So basically all these possible combinations of 1 could be inserted in valid subsets from 2 to 30
        // Why considering 1 seperately? 1 is crazy element and while taking
        int ans = solve(2, 1, 1) * 1ll * pow(2, freq[1], MOD) % MOD;
        return ans;
    }


};