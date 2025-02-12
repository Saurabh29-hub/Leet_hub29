class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
public:
    int maximumSum(vector<int>& nums) {
        // Use a hash map to store maximum numbers for each digit sum
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;
        
        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            
            // If we find a number with same digit sum
            if (digitSumMap.count(digitSum)) {
                maxSum = max(maxSum, num + digitSumMap[digitSum]);
                // Update the map with the larger number
                digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
            } else {
                digitSumMap[digitSum] = num;
            }
        }
        
        return maxSum;
    }
};
