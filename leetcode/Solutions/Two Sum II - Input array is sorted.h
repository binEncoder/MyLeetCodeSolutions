class Solution_TwoSumII{
public:
	// Input array is sorted 超时…… 000000000000那种
    vector<int> twoSum(vector<int>& numbers, int target) {
		int realTarget = target;
        for( auto it = numbers.begin(); it != numbers.end(); it++ ){
			realTarget = target - *it;
			auto res = find(it + 1, numbers.end(), realTarget);
			if( res != numbers.end() ){
				return { (int)(it - numbers.begin() + 1), (int)(res - numbers.begin() + 1) };
			}
		}
    }

	// best beat 98.71% 就是two sum I的解法，不过从1开始编址……
	vector<int> twoSumOA(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> res;
		auto idx = nums.size();
		for (idx = 0; idx < nums.size(); idx++) {
			map[nums[idx]] = idx;
		}

		for (idx = 0; idx < nums.size(); idx++) {
			const int anotherNum = target - nums[idx];
			if ((map.find(anotherNum) != map.end())
				&& (idx != map[anotherNum])) {
				res.push_back(idx + 1);
				res.push_back(map[anotherNum] + 1 );
				break;
			}
		}
		return res;
	}

	// 既然是有序的，那么给两个下标，往中间夹逼
	vector<int> twoSumOA2(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r)
        {
            if(numbers[l]+numbers[r]==target)
                break;
            if(numbers[l]+numbers[r]<target)
                l++;
            else 
                r--;
        }
        return vector<int>({l+1,r+1});
    }
};
