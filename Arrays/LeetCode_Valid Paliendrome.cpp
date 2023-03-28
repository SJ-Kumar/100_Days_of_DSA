class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }
        string reversedString = cleanString;
        reverse(reversedString.begin(), reversedString.end());
        return cleanString == reversedString;
    }
};
