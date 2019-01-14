/**
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * Example 1:
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * Follow up:
 * What if the inputs contain unicode characters? 
 * How would you adapt your solution to such case?
 */

class Solution_ValidAnagram {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> ump;
        for (char c : s) ump[c]++;
        for (char c : t) 
            if (ump.find(c) == ump.end() || ump[c] == 0)
                return false;
            else ump[c]--;
        
        for (auto it = ump.begin(); it != ump.end(); it++) 
            if (it->second != 0) return false;
        return true;
    }
};