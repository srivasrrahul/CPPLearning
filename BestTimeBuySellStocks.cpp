//
// Created by Srivastava, Rahul on 27/05/21.
//
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        auto maxProfit = 0;
        auto minPriceSeen = prices[0]; //check for 0
        for (int j = 1; j< prices.size();++j) {
            //buy at j and sell at
            auto localSellPrice = prices[j];

            if (minPriceSeen < localSellPrice) {
                maxProfit = max(maxProfit,localSellPrice-minPriceSeen);
            }

            minPriceSeen = min(minPriceSeen,prices[j]);

        }

        return maxProfit;
    }
};

int main() {

}

