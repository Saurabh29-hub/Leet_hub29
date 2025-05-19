class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<= nums[2] || nums[0]+nums[2]<=nums[1] || nums[1]+nums[2]<=nums[0]) return "none";

        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int max=0;
        for(auto it:mpp)
        {
            if(it.second>max) max=it.second;
        }
        if(max==1) return "scalene";
        else if(max==2) return "isosceles";
        else return "equilateral";
    }
};