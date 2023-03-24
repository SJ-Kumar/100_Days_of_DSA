//Using Sets
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>set;
        for(int i=0;i<nums.size();i++){
            if(set.count(nums[i])>0){
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
        
    }
};


//Using Maps
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>numCounts;
        for(int n:nums){
            numCounts[n]++;
        }
        for(int i=0;i<nums.size();i++){
            if(numCounts[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};
