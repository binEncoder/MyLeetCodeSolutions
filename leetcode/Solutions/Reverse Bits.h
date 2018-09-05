class Solution_ReverseBits {
private:
	void exchangeBit(uint32_t *num, uint8_t m, uint8_t n){
		uint32_t mBit = *num & ((uint32_t)1<<m);
		uint32_t nBit = *num & ((uint32_t)1<<n);
		if( mBit ){
			*num |= (uint32_t)1<<n;
		}
		else{
			*num &= ~((uint32_t)1<<n);
		}

		if( nBit ){
			*num |= (uint32_t)1<<m;
		}
		else{
			*num &= ~((uint32_t)1<<m);
		}
	}
public:
	// best beat 83.41%
    uint32_t reverseBits(uint32_t num) {
		for( int m = 0, n = 31; m < n; m++, n-- ){
			exchangeBit(&num, m, n);
		}
		return num;
    }

	// best beat 83.41%
	uint32_t reverseBitsOA(uint32_t n) {
        uint32_t ans = 0;
        int offset = 1;
        while(n){
            int res = n%2;
            if(res) ans += (uint32_t)1<<(32-offset);
            offset++;
            n >>= 1;
        }
        return ans;
    }

	// best beat 100%
	uint32_t reverseBitsOA2(uint32_t n) {
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};

