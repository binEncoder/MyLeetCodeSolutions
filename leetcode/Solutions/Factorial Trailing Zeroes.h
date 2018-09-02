class Solution_FactorialTrailingZeroes {
public:
	// best beat 100% 当因子2和5存在时，便会产生尾0，实际上是求分解后因子5的个数
	int trailingZeroes(int n) {
        return (5 > n)? 0 :(n/5 + trailingZeroes(n/5));
    }
};
