class Solution {
public:
    void rec(vector<int>& nums, int idx, vector<int>& set, vector<vector<int>>& sets) {
        if(idx < 0) {
            sets.push_back(set);
            return;
        }
        int temp = nums[idx];
        set.push_back(temp);
        rec(nums, idx-1, set, sets);
        set.pop_back();
        while(idx>=0 && nums[idx]==temp) idx--;
        rec(nums, idx, set, sets);
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sets;
        vector<int> set;
        rec(nums, nums.size()-1, set, sets);
        return sets;
    }
};