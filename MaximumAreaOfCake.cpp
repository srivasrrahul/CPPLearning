//
// Created by Srivastava, Rahul on 03/06/21.
//
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        vector<int> hCuts;
        hCuts.push_back(0);
        for (auto hi : horizontalCuts) {
            hCuts.push_back(hi);
        }

        hCuts.push_back(h);

        vector<int> vCuts;
        vCuts.push_back(0);
        for (auto v : verticalCuts) {
            vCuts.push_back(v);
        }
        vCuts.push_back(w);

        unsigned long maxArea = 0;
        auto low = 0;
        auto high = 0;
        for (int j = 1;j<hCuts.size();++j) {
            long newArea = (long)(hCuts[j]-hCuts[j-1])*w;
            if (newArea > maxArea) {
                low = hCuts[j-1];
                high = hCuts[j];
                maxArea = newArea;
            }
        }

        //cout << low << "," << high << endl;

        maxArea = 0;
        for (int j = 1;j<vCuts.size();++j) {
            unsigned long newArea = (long)(vCuts[j]-vCuts[j-1])*(high-low);
            if (newArea > maxArea) {
                maxArea = newArea;
            }
        }

        return maxArea % (unsigned long)(pow(10.0,9.0)+7);
    }
};
