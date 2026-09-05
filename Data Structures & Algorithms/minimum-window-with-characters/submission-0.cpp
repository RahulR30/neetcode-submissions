class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty()) return "";

        vector<int> freq(128, 0); 
        for (char c : t) {
            freq[c] += 1;
        }

        int required = t.size(); 
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0) {
                required--;
            }
            freq[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
