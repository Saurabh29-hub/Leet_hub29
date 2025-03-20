

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Use stack<char> instead of stack<int>
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, return false
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the top of the stack matches the current closing bracket
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
                
                // Pop the matching opening bracket from the stack
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets were matched; otherwise, return false
        return st.empty();
    }
};
