class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the two strings have different lengths, they can't be anagrams.
        if (s.size() != t.size()) {
            return false;
        }
        
        // Create a hash map to store the frequency of each character in the first string.
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        
        // Iterate through the second string and decrement the frequency of each character in the hash map.
        // If a character's frequency becomes negative, then it means the second string has more occurrences of that character than the first string,
        // and therefore, the second string can't be an anagram of the first string.
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]--;
            if (freq[t[i]] < 0) {
                return false;
            }
        }
        
        // If we've reached this point, then the second string is an anagram of the first string.
        return true;
    }
};
