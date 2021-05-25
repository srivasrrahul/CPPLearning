//
// Created by Srivastava, Rahul on 16/05/21.
//
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<int> retValue;
        auto j = 0;
        auto k = nums.size()-1;

        while (j <= k) {
            retValue.push_back(nums[j]);
            retValue.push_back(nums[k]);
            j++;
            k--;
        }

        std::copy(retValue.begin(),retValue.end(),nums.begin());
    }
};
