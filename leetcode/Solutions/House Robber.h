class Solution_HouseRobber {
public:
	// best beat 100%
    int rob(vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0; i < nums.size(); i++)		{
			if (i%2 == 0){
				a = ::max(a+nums[i], b);
			}
			else{
				b = ::max(a, b+nums[i]);
			}
		}
		
		return ::max(a, b);
    }

	/*
	 * f(0) = nums[0]
	 * f(1) = max(num[0], num[1])
	 * f(k) = max( f(k-2) + nums[k], f(k-1) )
	 */
	int robOA(vector<int>& nums, int n){
		if( n == 0 )	return nums[0];
		if( n == 1 )	return ::max( nums[0], nums[1] );
		return ::max(robOA(nums, n - 2) + nums[n], robOA(nums, n - 1));
	}

	// beautiful but  Time Limit Exceeded!
	int robOA(vector<int>& nums){
		if( nums.size() == 0 )	return 0;
		return robOA(nums, nums.size()-1);
	}

	// best beat 14.41%
	int robOA2(vector<int>& nums){
		size_t itemNums = nums.size();
		if( itemNums == 0 )		return 0;
		if( itemNums < 2 )		return (itemNums == 1)?(nums[0]):(::max(nums[0], nums[1]));

		vector<int> dp = nums;			// 分配空间耗时过多
		dp[0] = nums[0];
		dp[1] = ::max(nums[0], nums[1]);
		for( size_t i = 2; i < itemNums; i++ ){
			dp[i] = ::max( dp[i-2]+nums[i], dp[i-1] );
		}
		return dp[itemNums-1];
	}

	// best beat 100%
	int robOA3(vector<int>& nums){
		size_t itemNums = nums.size();
		
		int dp[2] = {0, 0};
		for( size_t i = 0; i < itemNums; i++ ){
			// size_t == unsinged long， %2处理后，不影响下标
			dp[i%2] = ::max( dp[(i-2)%2]+nums[i], dp[(i-1)%2] );
		}
		return ::max(dp[0], dp[1]);
	}
};
