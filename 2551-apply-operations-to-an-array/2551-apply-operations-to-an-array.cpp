class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n= nums.size();
        vector<int> arr(n);
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
           if(nums[i]!=0)
           {
              arr[j]=nums[i];
              j++;
           }
        }
        return arr;
    }
};