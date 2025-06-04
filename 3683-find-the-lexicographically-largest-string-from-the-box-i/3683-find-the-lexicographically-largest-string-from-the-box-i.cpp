class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        
        int n = word.length();
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            int k = min(n - i, n - numFriends + 1);
            string current = word.substr(i, k);
            ans = max(ans, current);
        }
        
        return ans;
    }
};
