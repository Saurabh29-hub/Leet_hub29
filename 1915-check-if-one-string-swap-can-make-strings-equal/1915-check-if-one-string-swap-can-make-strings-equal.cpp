class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1= s1.size();
        int n2= s2.size();
        if(n1!=n2) return false;
        int ind1=-1;
        int ind2=-1;
        
        int cnt=0;
        for(int i=0;i<n1;i++)
        {
            if(s1[i]!=s2[i])
            { 
                cnt++;
                if(cnt==1) ind1=i;
                if(cnt==2) ind2=i;
            }
        }
        if((ind1!=-1 && ind2!=-1) && ((s1[ind1]!=s2[ind2]) || s1[ind2]!=s2[ind1])) return false;
        if(cnt==2 || cnt==0) return true;
        else return false;
    }
};