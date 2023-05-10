class Solution {
public:
    bool isValid(string s) {
        stack<char>St;
        unordered_map<char, char> mp = {
        {')', '('},
        {']', '['},
        {'}', '{'}
        };

        for(char c: s){
            if(c=='(' || c=='[' || c=='{'){
                St.push(c);
            }
            else if(mp.count(c) && !St.empty() && St.top()==mp[c]){
                St.pop();
            }
            else{
                return false;
            }
        }
        return St.empty();

    }
};
