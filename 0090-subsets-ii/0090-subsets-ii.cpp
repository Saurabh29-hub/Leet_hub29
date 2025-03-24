

class Solution {
public:
    void solve(int ind, vector<int> &out, vector<vector<int>> &res, vector<int> &nums) {
        res.push_back(out); // Store the current subset

        for (int i = ind; i < nums.size(); i++) {
            // Skip duplicates
            if (i > ind && nums[i] == nums[i - 1]) continue;

            out.push_back(nums[i]);
            solve(i + 1, out, res, nums);
            out.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        
        // Sort nums to ensure duplicate elements are adjacent
        sort(nums.begin(), nums.end());

        solve(0, output, res, nums);
        return res;
    }
};

