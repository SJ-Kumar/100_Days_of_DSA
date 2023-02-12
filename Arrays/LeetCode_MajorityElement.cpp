//Brute Force Approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};


//Divide and Conquer

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
    
    int majorityElement(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        int l = majorityElement(nums, left, mid);
        int r = majorityElement(nums, mid + 1, right);
        
        if (l == r) {
            return l;
        }
        
        int lCount = count(nums, left, right, l);
        int rCount = count(nums, left, right, r);
        
        return lCount > rCount ? l : r;
    }
    
    int count(vector<int>& nums, int left, int right, int target) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
};

