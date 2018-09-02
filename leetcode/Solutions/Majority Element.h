/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */
// https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C++-with-Explanations
class Solution_MajorityElement {
public:
	// find a item which appears more than ⌊ n/2 ⌋ times

	// sort……
	// best beat 51.34%
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		return nums[nums.size()/2];
    }

	// best beat 97.81% Moore Voting Algorithm
	int majorityElement(vector<int>& nums){
		int major = nums[nums.size() - 1], count = 1;
		if( nums.size() < 2 )	return nums[0];
		for( int i = nums.size() - 2; i >= 0; i-- ){
			if( !count ){
				count++;
				major = nums[i];
			}
			else{
				count += (major == nums[i])?1:(-1);
			}
		}
		return major;
	}

	// Hash Table item-item appears times
	int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }

	// Random 由于寻找的是超过半数的元素，选中的概率有50%……
	int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }

public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
	// Divide and Conquer
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        //int mid = left + ((right - left) >> 1);
		int mid = (left + right)/2;
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }

	// Bit Manipulation 统计每一位上1出现的次数，超过元素个数半数的话，和结果'或'上
	int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};
