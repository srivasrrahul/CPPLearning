#include <vector>
#include <set>
#include <utility>
#include <numeric>
#include <iostream>
using namespace std;
struct Hash {
    unsigned long operator()(const vector<int> & v) const {
        return std::accumulate(v.begin(),v.end(),0);
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) {
            vector<vector<int>> retValue;
            return retValue;
        }
        //auto twoSum = [&](int x,int y)
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        for (int j = 0;j<nums.size();++j) {
            for (int k = j+1;k < nums.size()-1;++k) {
                auto pending = -(nums[j] + nums[k]);
                if (binary_search(nums.begin()+k+1,nums.end(),pending)) {
                    vector<int> s{nums[j],nums[k],pending};
                    res.insert(s);
                }

                if (nums[j] == nums[k] && nums[j] == pending) {
                    //All are same
                    break;
                }

            }
        }

        //cout << "gello";
        vector<vector<int>> retValue;
        retValue.insert(retValue.end(),res.begin(),res.end());
        return retValue;
    }
};