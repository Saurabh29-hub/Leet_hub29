#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step #1: Sieve of Eratosthenes to find all primes up to 'right'
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step #2: Collect all primes in range [left,right]
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step #3: Handle edge case where fewer than two primes exist
        if (primes.size() < 2) {
            return {-1,-1};
        }

        // Step #4: Find closest pair of primes
        int minDiff = INT_MAX;
        vector<int> result(2);

        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }

        return result;
    }
};
