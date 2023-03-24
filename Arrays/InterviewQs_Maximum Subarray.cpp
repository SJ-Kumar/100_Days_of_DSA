//Using Kandane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            currSum=currSum+nums[i];
            maxSum=max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};


//Divide and Conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return divideandconquer(nums,0,nums.size()-1);
    }
    private:
        int divideandconquer(vector<int>nums,int left,int right){
            if(left==right) return nums[left];
            int mid=left+(right-left)/2;
            int leftSum=divideandconquer(nums,0,mid);
            int rightSum=divideandconquer(nums,mid+1,right);
            int crossSum=crossMidSum(nums,left,right,mid);
            return max(max(leftSum,rightSum),crossSum);
        }

        int crossMidSum(vector<int>nums,int left,int right,int mid){
            int leftMaxSum=INT_MIN;int sum=0;
            for(int i=mid;i>=left;i--){
                sum=sum+nums[i];
                leftMaxSum=max(leftMaxSum,sum);
            }
            int rightMaxSum=INT_MIN;sum=0;
            for(int i=mid+1;i<=right;i++){
                sum=sum+nums[i];
                rightMaxSum=max(rightMaxSum,sum);
            }
            return leftMaxSum+rightMaxSum;
        }
};
