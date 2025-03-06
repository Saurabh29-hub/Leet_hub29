class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Start backtracking from index 0
        backtrack(nums, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Try including each remaining element
        for (int i = start; i < nums.size(); i++) {
            // Include the current element
            current.push_back(nums[i]);
            
            // Recursively generate subsets with this element
            backtrack(nums, i + 1, current, result);
            
            // Backtrack: remove the element to try the next possibility
            current.pop_back();
        }
    }
};
