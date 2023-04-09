class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        if(s.size()==0){
            return 0;
        }
        int length1=1;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                i=m[s[i]]+1;
                m.clear();
            }
            m[s[i]]=i;
            int length2=m.size();
            length1=max(length1,length2);
        }
        return length1;

    }
};
