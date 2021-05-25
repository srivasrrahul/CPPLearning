//
// Created by Srivastava, Rahul on 23/05/21.
//

#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:


    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> longestString;
        auto maxLen = 1;
        auto from = 0;
        auto to = 0;
        if (s.size() == 0) {
            return 0;
        }

        longestString.insert(make_pair(s[0],0));



        for (int j = 1;j<s.size();++j) {
            auto current = s[j];
            to = j;
            if (longestString.find(current) == longestString.end()) {
                //longestString.insert(make_pair(current,j));
                longestString[current] = j;
                //indexesInStr.insert(j);
                //maxLen = max(maxLen,to-from+1);

            }else {
                auto lastChIndex = longestString.find(current)->second;
                from = max(from,lastChIndex+1);
                longestString.erase(current);
                longestString[current] = j;

            }

            maxLen = max(maxLen,to-from+1);

            //cout << j << " " << from << ":" << to << "=> " << maxLen << endl;
        }

        return maxLen;
    }
};

 int main() {

 }
