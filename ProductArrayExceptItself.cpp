//
// Created by Srivastava, Rahul on 27/05/21.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward;
        vector<int> backward;

        forward.push_back(nums[0]);

        for (int j = 1;j<nums.size();++j) {
            forward.push_back(nums[j]*forward.back());
        }

        backward.push_back(nums.back());

        for (int j = nums.size()-2;j>=0;--j) {
            backward.push_back(nums[j]*backward.back());
        }

       // reverse(backward.begin(),backward.end());
        vector<int> result;

        for (int j = 0;j<nums.size();++j) {
            int prev = j-1;
            auto mul = 1;
            if (prev >= 0) {
                mul = mul * forward[prev];
            }

            int next = j+1;
            if (next < nums.size()) {
                mul = mul * backward[next];
            }

            result.push_back(mul);

        }

        return result;
    }
};
