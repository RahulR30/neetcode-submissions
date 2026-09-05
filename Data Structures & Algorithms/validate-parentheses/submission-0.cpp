class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        unordered_map<char, char> brackets = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (char c : s) {
            if (brackets.count(c)) {
                parentheses.push(c);
            }
            else {
                if (parentheses.empty() || brackets[parentheses.top()] != c) {
                    return false;
                }
                parentheses.pop();
            }
        }

        return parentheses.empty();
    }
};
