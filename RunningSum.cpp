//
// Created by Srivastava, Rahul on 03/05/21.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        auto sum = 0;
        for (int j = 0;j<nums.size();++j) {
            sum += nums[j];
            result.push_back(sum);
        }

        return result;
    }
};

int main() {
    vector<int> v{ 1, 2, 3, 4};
    auto obj = new Solution();
    auto res = obj->runningSum(v);
    for (auto c : res) {
        cout << c <<",";
    }

    cout << endl << res.size();
    return 0;
}
