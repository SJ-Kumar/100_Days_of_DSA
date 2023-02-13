class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        return d_and_c(nums,0,nums.size()-1);
    }
private:
    
    int d_and_c(vector <int> nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        int mid=left+(right-left)/2;
        int leftSum=d_and_c(nums,left,mid);
        int rightSum=d_and_c(nums,mid+1,right);
        int crossSum=cross(nums,left,right,mid);

        return max(max(leftSum,rightSum),crossSum);
    }
    int cross(vector<int>nums,int left,int right,int mid){
        int leftMaxSUM=INT_MIN;
        int sum=0;
        for(int i=mid;i>=left;i--){
            sum+=nums[i];
            leftMaxSUM=max(leftMaxSUM,sum);
        }
        int rightMaxSUM=INT_MIN;
        sum=0;
        for(int i=mid+1;i<=right;i++){
            sum+=nums[i];
            rightMaxSUM=max(rightMaxSUM,sum);
        }
        return leftMaxSUM + rightMaxSUM;
    }
};