class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int n=words.size();
        res.push_back(words[0]);
        for(int i=1;i<n;i++)
        {
           if(groups[i]!=groups[i-1])
           {
              res.push_back(words[i]);
           }
        }
        return res;
        
    }
};