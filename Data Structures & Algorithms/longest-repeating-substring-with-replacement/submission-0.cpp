class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int cur_max = 0;
        int left = 0;
        int maxFreq = 0;

        for(int cur = 0; cur < s.size(); cur++){
            count[s[cur] - 'A']++;
            maxFreq = max(maxFreq, count[s[cur] - 'A']);

            while ((cur - left + 1) - maxFreq > k){
                count[s[left] - 'A']--;
                left++;
            }

            cur_max = max(cur_max, cur - left + 1);
        }
        return cur_max;
    }

};
