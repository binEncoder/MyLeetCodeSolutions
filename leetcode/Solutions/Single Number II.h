class Solution_SingleNumberII {
public:
    int singleNumber(vector<int>& nums) {
        int low = 0, high = 0;

        for (auto i = nums.begin(); i != nums.end(); i++) {
            low ^= *i & ~high;
            high ^= *i & ~low;
        }
        return low;
    }

    // 69.05% 通用解法
    /*
            0111
            0111
            0111
            1010
            1010
            1010
            0110        *
           -------
            3473  统计每个位置上出现的1的次数， 每一个位mod 3，得到下面这个数，下面这个二进制数即为数组中只出现了一次的数字
            0110        *
    */
    int singleNumber(vector<int>& nums) {
        int result = 0, itorRange = sizeof(int)*8;

        for( auto i = itorRange - 1; i >= 0; i-- ){
            int times = 0;
            for( auto num: nums ){
                times += (num >> i)&1;
            }
            result |= ((times%3)<<i);
        }
        return result;
    }
    
};