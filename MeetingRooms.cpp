//
// Created by Srivastava, Rahul on 30/05/21.
//
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int> & v1,const vector<int> & v2) {
            return v1[0] < v2[0];
        };

        auto comp1 = [](const vector<int>  & v1,const vector<int>  & v2) {
            return v1[1] < v2[1];
        };

        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int,
                vector<int>,less<int>> pq;

        pq.push(intervals[0][1]);

        // for (auto & iv : intervals) {
        //     cout <<iv[0] <<"," << iv[1] <<endl;
        // }

        unsigned long maxDepth = 1;
        for (int j = 1;j<intervals.size();++j) {
            vector<int> temp;
            //cout << "For " << intervals[j][0] << "," << intervals[j][1] << endl;
            while (pq.size() > 0) {
                auto & top = pq.top();
                //cout << "top " << top[0] << "," << top[1] << endl;
                if (top > intervals[j][0]) {
                    //cout << "found conflict" << top[0] << "," << top[1] << endl;
                    temp.push_back(top);
                    pq.pop();
                }else {
                    break;
                }
            }

            maxDepth = max(maxDepth,temp.size()+1);
            for (auto & v : temp) {
                pq.push(v);
            }

            pq.push(intervals[j][1]);
        }

        return maxDepth;




    }
};
int main() {

}