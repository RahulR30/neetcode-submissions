class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_numbers;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = seen_numbers.find(complement);

            if (it != seen_numbers.end()) {
                return {it->second, i};
            } 
            
            seen_numbers[nums[i]] = i;
        }
        return {};
    }
};
