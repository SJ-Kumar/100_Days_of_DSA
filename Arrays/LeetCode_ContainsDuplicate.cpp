class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int result = count(nums.begin(), nums.end(), nums[i]);
            if(result>1){
                return true;
            }
        }
        return false;
    }
};
