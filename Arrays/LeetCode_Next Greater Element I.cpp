class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            int next_greater = -1;
            bool found = false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    found = true;
                }
                if(found && nums2[j]>nums1[i]){ // check for the Next Greater Element
                    next_greater = nums2[j];
                    break;
                }
            }
            result.push_back(next_greater); // add the Next Greater Element to the result vector
        }
        return result;
    }
};
