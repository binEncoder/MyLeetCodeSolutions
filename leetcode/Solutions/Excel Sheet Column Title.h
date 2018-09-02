class Solution_ExcelSheetColumnTitle {
public:
	// best beat 100%
    string convertToTitle(int n) {
        string ret;
		int remainder = n, tmp = 0;
		while(remainder){
			tmp = ((remainder% 26) == 0) ? 26: remainder % 26;
			ret.push_back( 'A'+ tmp - 1 );
			remainder -= tmp;
			remainder /= 26;
		}
		reverse(ret.begin(), ret.end());
		return ret;
    }
};
