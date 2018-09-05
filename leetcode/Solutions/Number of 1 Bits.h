class Solution_Numberof1Bits {
public:
	// best beat 62.69%
    int hammingWeight(uint32_t n) {
        int ret = 0;
		while( n ){
			ret++;
			n &= (n-1);
		}
		return ret;
    }
};
