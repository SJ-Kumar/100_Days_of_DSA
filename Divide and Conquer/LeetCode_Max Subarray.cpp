class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return divideAndConquer(nums, 0, nums.size()-1);
    }

private:
    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right-left)/2;
        int leftSum = divideAndConquer(nums, left, mid);
        int rightSum = divideAndConquer(nums, mid+1, right);
        int crossSum = crossMidSum(nums, left, right, mid);
        return max(max(leftSum, rightSum), crossSum);
    }

    int crossMidSum(vector<int>& nums, int left, int right, int mid) {
        int leftMaxSum = INT_MIN, sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftMaxSum = max(leftMaxSum, sum);
        }
        int rightMaxSum = INT_MIN;
        sum = 0;
        for (int i = mid+1; i <= right; i++) {
            sum += nums[i];
            rightMaxSum = max(rightMaxSum, sum);
        }
        return leftMaxSum + rightMaxSum;
    }
};
