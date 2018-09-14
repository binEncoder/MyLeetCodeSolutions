#include "common.h"

class Solution_IsomorphicStrings {
public:
	// best beat 99.34%
    bool isIsomorphic(string s, string t) {
        size_t n = s.size(), i;
		vector<int> vec1(256,-1), vec2(256,-1);
        for (i = 0; i < n; ++i) {
            if (vec1[s[i]] != vec2[t[i]]) return false;
            vec1[s[i]] = i;
            vec2[t[i]] = i;
        }
        return true;
    }
};
