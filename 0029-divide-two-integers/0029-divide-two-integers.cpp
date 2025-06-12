class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to long and use abs to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        // Subtract the divisor multiplied by powers of 2
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Apply the sign
        if (isNegative)
            result = -result;

        // Clamp result to 32-bit signed int range
        return max((int)INT_MIN, min((int)INT_MAX, (int)result));
    }
};
