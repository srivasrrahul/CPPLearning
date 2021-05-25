//
// Created by Srivastava, Rahul on 22/05/21.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <numeric>
#include <set>


using namespace std;
class HashFunction {

public:
    size_t operator()(const vector<int> & t) const {
        return t[0] + t[1] + t[2];
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int > indexes;
        for (int j = 0;j<nums.size();++j) {
            auto num = nums[j];
            if (indexes.find(num) != indexes.end()) {
                auto count =  indexes.find(num)->second;
                indexes.insert(make_pair(num,++count));
            }else {
                indexes.insert(make_pair(num,1));
            }
        }

        set<vector<int>> res;

        for (int j = 0; j < nums.size()-2;++j) {
            for (int k = j+1; k < nums.size()-1;++k) {
                auto pending = -(nums[j] + nums[k]);
                if (indexes.find(pending) != indexes.end()) {
                    auto count = indexes.find(pending)->second;
                    //remove j and k from equation
                    vector<int> v {nums[j],nums[k],pending};
                    sort(v.begin(),v.end());
                    res.insert(v);
                }
            }
        }

        vector<vector<int> > retValue(res.begin(),res.end());

        return retValue;
    }
};

 int main() {
     auto v = vector<int> {-1,0,1,2,-1,-4};
     auto res = (new Solution())->threeSum(v);
     for (auto & r : res) {
         for (auto x : r) {
             cout << x <<",";
         }

         cout<<endl;
     }

 }