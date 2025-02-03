class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1= 0;
        int cnt= 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                cnt++;
                ans1= max(cnt,ans1);
            }
            else cnt=0;
        }
        cnt=0;
        int ans2=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                cnt++;
                ans2= max(cnt,ans2);
            }
            else cnt=0;
        }
        return ans1>ans2 ? ans1+1:ans2+1;

    }
};