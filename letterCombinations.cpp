class Solution {
public:
    void solve(vector<string>& ans, string digits, int i, string& s, map<int, vector<char>>& mp) {
        if (i == digits.length()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[i] - '0';
        for (int j = 0; j < mp[digit].size(); j++) {
            s += mp[digit][j];
            solve(ans, digits, i + 1, s, mp);
            s.pop_back();  // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        map<int, vector<char>> mp({
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        });

        vector<string> ans;
        string s = "";
        solve(ans, digits, 0, s, mp);
        return ans;
    }
};