class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>charCounts;
        for(char c:s){
            charCounts[c]++;
        }
        for(int i=0;i<s.size();i++){
            if(charCounts[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
