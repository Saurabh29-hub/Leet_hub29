class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        // Count the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find the dominant element
        int dominant = -1;
        for (auto& [num, count] : freq) {
            if (count * 2 > n) {
                dominant = num;
                break;
            }
        }
        
        if (dominant == -1) return -1;
        
        int leftCount = 0, rightCount = freq[dominant];
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
                rightCount--;
            }
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};
