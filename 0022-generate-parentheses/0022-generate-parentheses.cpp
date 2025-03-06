class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: if the current string length equals 2*n, we have a complete combination
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        
        // We can add an opening parenthesis if we haven't used all n
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // We can add a closing parenthesis if there are unclosed opening parentheses
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};
