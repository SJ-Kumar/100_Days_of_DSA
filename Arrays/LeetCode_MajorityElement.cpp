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
        return majorityelement(nums,0,nums.size()-1);
    }

    int majorityelement(vector <int>nums,int  left,int right){
        if(left==right){
            return nums[left];
        }
        int mid=(left+(right-left)/2);
        int l=majorityelement(nums,left,mid);
        int r=majorityelement(nums,mid+1,right);
        if(l==r){
            return l;
        }
        int lcount=count(nums,left,right,l);
        int rcount=count(nums,left,right,r);

        return lcount>rcount?l:r;  
    }

    int count(vector<int>nums,int left,int right,int target){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                count++;
            }
        }
        return count;
    }
};
