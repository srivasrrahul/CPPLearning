//
// Created by Srivastava, Rahul on 16/05/21.
//
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        auto maxWealth = numeric_limits<int>::min();
        for (auto & account : accounts) {
            auto accountWealth = accumulate(account.begin(),account.end(),0);
            if (accountWealth > maxWealth) {
                maxWealth = accountWealth;
            }
        }

        return maxWealth;
    }
};