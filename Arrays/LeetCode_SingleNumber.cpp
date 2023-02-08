class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int a = count(nums.begin(), nums.end(), nums[i]);
            if (a == 1) {
                return nums[i];
            }
        }
        return 0;
    }
};
