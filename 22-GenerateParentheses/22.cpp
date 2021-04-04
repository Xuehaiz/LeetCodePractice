class Solution {
public:
    vector<string> ans;
    void backtrack(string current_string, int left, int right, int n) {
        if (current_string.length() == 2 * n) {
            ans.push_back(current_string);
            return;
        }
        if (left < n) backtrack(current_string + "(", left + 1, right, n);
        if (left > right) backtrack(current_string + ")", left, right + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};