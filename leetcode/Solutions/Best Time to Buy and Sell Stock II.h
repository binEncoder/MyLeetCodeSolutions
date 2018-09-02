class Solution_BestTimeToBuyAndSellStockII {
public:
    // 98.42%
    int maxProfit(vector<int>& prices) {
        // 找到连续变化的区间，以最大减最小( 可以用迭代的方法代替 )
        int profit = 0;
        for (auto i = prices.cbegin(); i != prices.cend(); i++) {
            if (i + 1 != prices.cend() && ( *i < *(i+1) ) ) {
                profit += *(i + 1) - *i;
            }
        }
        return profit;
    }
};