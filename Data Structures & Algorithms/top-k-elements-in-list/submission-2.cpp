class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for(int value : nums){
            frequency[value]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto const& [key, val] : frequency){
            buckets[val].push_back(key);
        }

        vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; --i){
            for(int num: buckets[i]){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
