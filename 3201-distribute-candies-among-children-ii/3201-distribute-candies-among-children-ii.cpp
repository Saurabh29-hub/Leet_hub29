class Solution {
public:
    const int MOD = 1e9 + 7;

    long long C(long long n) {
        // Compute C(n + 2, 2) = (n + 2)(n + 1)/2
        if (n < 0) return 0;
        return (n + 2) * (n + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        // Inclusion-Exclusion
        long long total = C(n);
        total -= 3 * C(n - limit - 1);
        total += 3 * C(n - 2 * limit - 2);
        total -= C(n - 3 * limit - 3);
        return total;
    }
};