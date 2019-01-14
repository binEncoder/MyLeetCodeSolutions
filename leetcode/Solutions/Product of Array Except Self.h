
// Note: Please solve it without division and in O(n).
// Could you solve it with constant space complexity? 
// (The output array does not count as extra space for the purpose of space complexity analysis.)

// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

/**
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 */
class Solution_Product_of_ArrayExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
		for (size_t idx = 0; idx < nums.size(); idx++) {
			for (size_t idxRet = 0; idxRet < ret.size(); idxRet++) {
				if (idx != idxRet) {
					ret[idxRet] *= nums[idx];
				}
			}
		}
		return ret;
    }

    vector<int> productExceptSelf_OA(vector<int>& nums) {
		vector<int> ret;
		size_t size = nums.size();
		int idx = 0，num = 1;
        // 滞后的num改变，避免乘以当前nums[idx]
		for (idx = 0; idx < static_cast<int>(size); idx++) {
			ret.push_back(num);
			num *= nums[idx];
		}
		num = 1;
		for (idx = size-1; idx > -1; idx--) {
			ret[idx] = ret[idx] * num;
			num *= nums[idx];
		}
		return ret;
	}
};