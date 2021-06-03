//
// Created by Srivastava, Rahul on 29/05/21.
//
#include <vector>
#include <queue>
#include <utility>
#include <list>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](vector<int> p1,vector<int>  p2)  {
            auto d1 = p1[0]*p1[0]+p1[1]*p1[1];
            auto d2 = p2[0]*p2[0]+p2[1]*p2[1];
            return d1>d2;
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(distance)> pq(distance);

        for (auto & point : points) {
            pq.push(point);
        }

        pq.t

        vector<vector<int>> retValue;
        for (int j = 0;j<k;++j) {
            retValue.push_back(pq.top());
            pq.pop();
        }

        return retValue;
    }
};

 int main() {

 }
