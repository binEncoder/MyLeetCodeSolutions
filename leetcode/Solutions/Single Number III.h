class Solution_SingleNumberIII {
public:
    // 97.88% 
    vector<int> singleNumber(vector<int>& nums) {
        int left = 0, right = 0, xorRes = 0, andNum = 1, lastOneIdx = 0;
        for (auto i : nums) {
            xorRes ^= i;
        }        
        for (int i = 0; i < 32; i++) {
            if (xorRes & andNum) {
                lastOneIdx = i;
                break;
            }
            andNum <<= 1;
        }
        for (auto i : nums) {
            if (i & (1<< lastOneIdx)) {
                left ^= i;
            } 
            else {
                right ^= i;
            }
        }
        return vector<int>{left, right};
    }

    // 先得到所有元素 异或 后的值，该值的每一个为1的位都可以作为 分组 的依据
    vector<int> singleNumber(vector<int>& nums) {
        int left = 0, right = 0, xorRes = 0, andNum = 1, lastOneIdxShiftValue = 0;
        for (auto i : nums) {
            xorRes ^= i;
        }
        lastOneIdxShiftValue = (xorRes &(xorRes - 1)) ^ xorRes;
        //lastOneIdxShiftValue = xorRes & (~(xorRes - 1));
        for (auto i : nums) {
            if (i & lastOneIdxShiftValue) {
                left ^= i;
            }
            else {
                right ^= i;
            }
        }
        return vector<int>{left, right};
    }
};