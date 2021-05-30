//
// Created by Srivastava, Rahul on 25/05/21.
//
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> retValue;

        if (intervals.empty()) {
            return retValue;
        }
        sort(intervals.begin(),intervals.end(),[](const vector<int>& v1,const vector<int>& v2) -> bool {
            return (v1[0] < v2[0]);
        });


        retValue.push_back(intervals[0]);

        for (int j = 1 ; j < intervals.size() ;++j) {
            auto prev = retValue.back();
            auto current = intervals[j][0];
            if (prev[1] >= current) {
                retValue.pop_back();
                retValue.push_back(vector<int>{prev[0],max(prev[1],intervals[j][1])});
            }else {
                retValue.push_back(intervals[j]);
            }
        }

        return retValue;
    }
};

int main() {
    auto s = Solution();
    auto intervals = vector<vector<int>> {vector<int>{2,6},vector<int>{8,10},vector<int>{15,18},vector<int>{1,3},};
    auto retValue = s.merge(intervals);
    for (auto &k : retValue) {
        cout <<k[0] << "," << k[1] << endl;
    }

}
