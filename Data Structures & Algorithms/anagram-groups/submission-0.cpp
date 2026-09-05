class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>  groups;
        for(string s : strs){
            int count[26] = {0};
            string key;

            for (char c : s) count[c - 'a']++;

            for(char c : count){
                key.push_back(c);
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto const& [key, val]: groups) {
            result.push_back(val);
        }
        
        return result;
    }
};
