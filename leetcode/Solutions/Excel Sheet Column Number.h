class Solution_ExcelSheetColumnNumber {
private:
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

	int strcomp(const char *pa, const char *pb){
		int len[] = {strlen(pa), strlen(pb)};
		if( len[0] > len[1] ){
			return 1;
		}
		else if(len[0] < len[1]){
			return -1;
		}
		else{
			return strcmp(pa, pb);
		}
	}
public:
	// best beat 98.26% binary search 好处是一开始就确定了最大范围，否则数据可能出现溢出
	int titleToNumber(string s) {
        int min = 1, max = INT_MAX;

		// 在int范围内不可能查找到
		if( strcomp( s.c_str(), convertToTitle(max).c_str()) > 0 )
			return -1;

		while( min < max ){
			int mid = min / 2 + max / 2;	// 避免先加了之后数据溢出
			string res{convertToTitle(mid)};
			int cmp = strcomp(res.c_str(), s.c_str());
			if( !cmp ){
				return mid;
			}
			else if( cmp > 0 ){
				max = mid - 1;
			}
			else{
				min = mid + 1;
			}
		}
		return min;			// 跳出后返回，与二分查找类似
    }

	// best beat 98.26%
	int titleToNumber(string s) {
		int ret = 0, lettersNum = 26, max = INT_MAX/lettersNum;
		// 判定数据在合适范围后再采取操作
		for( char c: s ){
			if( ret > max ){
				ret = -1;
				break;
			}
			ret *= lettersNum;

			if( ret > INT_MAX - (c-'A'+1) ){
				ret = -2;
				break;
			}
			ret += c - 'A' + 1;
		}
		return ret;
    }
};
