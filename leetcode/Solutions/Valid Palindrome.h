class Solution_ValidPalindrome {
public:
    // 左右两个指针往中间逼近，需要特别注意的就是left、right超边界问题
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left)) ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else { left++, right--; }
        }
	return true;
}
};