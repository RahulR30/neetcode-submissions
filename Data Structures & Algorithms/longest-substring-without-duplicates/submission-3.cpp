class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;  
        int left = 0, best = 0;
        
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            auto it = seen.find(c);
            if (it != seen.end() && it->second >= left)
                left = it->second + 1;
            seen[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
