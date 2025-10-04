class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the largest index i such that nums[i] < nums[i + 1]
        // This is the "pivot" - the rightmost character that can be increased
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // Step 2: If no such index exists, the permutation is the last permutation
        if (i >= 0) {
            // Step 3: Find the largest index j greater than i such that nums[i] < nums[j]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            
            // Step 4: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        
        // Step 5: Reverse the suffix starting at nums[i + 1]
        reverse(nums.begin() + i + 1, nums.end());
    }

};