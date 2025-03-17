class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2==1) return false;
        int cnt=0;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]+=1;
        }
        for(auto it:mpp)
        {
            int temp= it.second;
            cnt+= temp/2;
        }
        if(cnt==nums.size()/2) return true;
        else return false;
    }
};