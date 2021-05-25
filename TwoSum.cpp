//
// Created by Srivastava, Rahul on 22/05/21.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,vector<int> > valueIndexes;
        for (int j = 0; j< nums.size();++j) {
            auto x = nums[j];

            auto pending = target-x;

            if (valueIndexes.find(pending) != valueIndexes.end()) {
                //cout << "Found " << valueIndexes.find(pending)->second.size() << endl;
                result.push_back(j);
                result.push_back(valueIndexes.find(pending)->second.front());
                break;
            }

            if (valueIndexes.find(x) != valueIndexes.end()) {
                auto & vec = valueIndexes.find(x)->second;
                vec.push_back(j);
            }else {
                valueIndexes.insert(make_pair(x,vector<int>{j}));
            }
        }

        return result;
    }
};

int main() {
    auto s = Solution();
    auto v = vector<int> {2,7,11,15};
    auto res = s.twoSum(v,9);
    //cout << "Got res";
    for (auto t : res) {
        cout<<t <<",";
    }

    cout<<endl;
}