class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Best price to buy so far
            minPrice = min(minPrice, prices[i]);

            // Profit if we sell today
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};