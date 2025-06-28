class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++)
        {
           mpp[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++)
        {
            int x= nums1[i];
            int index= mpp[x];
            if(index== nums2.size()-1)
            {
                ans.push_back(-1);
                continue;
            }
            for(int i=index+1;i<nums2.size();i++)
            {
                if(nums2[i]>x)
                {
                    ans.push_back(nums2[i]);
                    break;
                }
                if(i==nums2.size()-1)
                {
                    ans.push_back(-1);
                    break;
                }
            }
            
            
        }
        return ans;
    }
};