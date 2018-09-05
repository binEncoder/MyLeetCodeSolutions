class Solution_RotateArray {
private:
	void exchange( vector<int>& nums, int m, int n ){
		if( (m == n) || ( m >= nums.size() ) || ( n >= nums.size() )){
			cout<<"error"<<endl;
			return;				
		}
		int tmp = nums[m];
		nums[m] = nums[n];
		nums[n] = tmp;
	}
public:
	void printVector( const vector<int>& nums ){
		for( auto item : nums )
			cout<<item<<' ';
		cout<<endl<<endl;
	}

	/* to be corrected */
	void rotate(vector<int>& nums, int k) {

		static int exTimes = 0;
		if( k == 0 ) return;
        if( k > 0 && k > nums.size() )		k %= nums.size();
		int std = nums.size() - k, right = std, left = 0, allowTimes = (1+k)*k/2;
		//while( /*left < right &&*/ left < allowTimes ){
		while(left < right){
			exchange(nums, left++, right++);
			exTimes++;
			if( right == nums.size() ){
				//std = (std+1)%k + (nums.size() - k);
				right = std;
				cout<<"reload right idx"<<endl;
			}
			cout<<"rightIdx:\t"<<right<<"\trightValue:\t"<<nums[right]<<endl;
			cout<<" leftIdx:\t"<<left<<"\t leftValue:\t"<<nums[left]<<endl;
			printVector(nums);
		}
		cout<<exTimes<<'\t'<<k<<endl;
		exTimes = 0;

#if 0	/* best beat 100% */
		size_t itemsNum = nums.size();
		if( itemsNum <= 0 )	return;
		if( k >= itemsNum ) k %= itemsNum;
		if( k == 0 )	return;

		reverse(nums.begin(), nums.end()-k);

		reverse(nums.end()-k, nums.end());

		reverse(nums.begin(), nums.end());
#endif
    }
};


int main(int argc, char *argv[]){
	Solution_RotateArray s;
#if 0
	vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	int k = 3;
	s.rotate(vec, k);


	vector<int> vec2{ -1,-100,3,99 };
	int k2 = 2;
	s.rotate(vec2, k2);
	for( auto item : vec2 )	cout<<item<<' ';
	cout<<endl;
#endif
	vector<int> vec3{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
	int k3 = 38;
	s.rotate(vec3, k3);
	s.printVector(vec3);

	return 0;
}

