class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        string ans="";
        char curr= s[0];
        ans+=curr;
        for(int i=1;i<s.size();i++)
        {
           if(s[i]!=curr)
           {
            curr=s[i];
            cnt=0;
           }
           if(s[i]==curr && cnt<2)
           {
             cnt++;
             ans+=s[i];
           } 
        }
        return ans;
    }
};