class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int max1 = robLinear(nums, 0, n - 2);
        
        int max2 = robLinear(nums, 1, n - 1);

        return max(max1, max2);
    }
    int robLinear(const vector<int>& nums, int start, int end) {
        int rob1 = 0; 
        int rob2 = 0;

        for (int i = start; i <= end; ++i) {
            int newRob = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }
};
