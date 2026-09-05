class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> s1_freq;
        map<char, int> s2_freq;
        for(char c : s1){
            s1_freq[c] += 1;
        }

        int left = 0;
        int right = s1.size() - 1; 

        for(int cur = 0; cur < s2.size(); cur++){
            s2_freq[s2[cur]] += 1;
            if (cur >= right) {
                if (s1_freq == s2_freq){
                    return true;
                }
                else{
                    if(s2_freq[s2[left]] == 1){
                        s2_freq.erase(s2[left]);
                    }
                    else{
                        s2_freq[s2[left]] -= 1;
                    }
                    left++;
                    right++;
                }
            }
        }
        return false;
    }
};
