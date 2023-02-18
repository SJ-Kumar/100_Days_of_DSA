class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        vector<int>result;
        for(int i=0;i<arr1.size();i++){
            bool valid=true;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    valid=false;
                    break;
                }
            }
            if(valid){
                result.push_back(arr1[i]);
            }
        }
        return result.size();
    }
};
