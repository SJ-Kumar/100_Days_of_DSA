class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> charCounts;
        for (char c : s) {
            charCounts[c]++;
        }
        for (char c : t) {
            charCounts[c]--;
        }
        for (auto p : charCounts) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
    }
};
