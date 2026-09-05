class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int max = 0;

        for (int x : s) {
            if (s.contains(x - 1)) continue;   // not the start of a run, skip

            int current = x;
            int counter = 1;
            while (s.contains(current + 1)) {   // walk forward through the run
                current++;
                counter++;
            }
            if (counter > max) max = counter;
        }
        return max;
    };
};
