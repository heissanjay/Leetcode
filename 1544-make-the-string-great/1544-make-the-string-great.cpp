class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;

        for (char c : s) {
            if (!stk.empty() && abs(stk.top() - c) == 32) {
                stk.pop(); 
            } else {
                stk.push(c);
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};
