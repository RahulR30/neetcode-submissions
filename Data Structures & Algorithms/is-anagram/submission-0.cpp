class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> char_counts(256, 0);

        for (size_t i = 0; i < s.length(); ++i) {
            char_counts[s[i]]++; 
            char_counts[t[i]]--; 
        }

        for (int count : char_counts) {
            if (count != 0) return false;
        }
        return true;
    }
};
