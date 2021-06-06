//
// Created by Srivastava, Rahul on 06/06/21.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

        unordered_map<char,vector<int>> charIndexes;

        for (int j = 0;j<s.length();++j) {
            charIndexes.emplace(s[j],vector<int>{});
            auto & indexes = charIndexes[s[j]];
            indexes.push_back(j);
        }



        //cout << charIndexes.size() << endl;

        std::function<bool(int,int)> checkPalindrome = [&](int low,int high) {
            if (low == high) {
                return true;
            }else {
                if (low == high-1) {
                    return s[low] == s[high];
                }else {
                    if (s[low] == s[high]) {
                        return checkPalindrome(low+1,high-1);
                    }else {
                        return false;
                    }
                }
            }
        };

        auto maxLen = 1;
        auto low = 0;
        auto high = 0;
        for (int j = 0;j<s.length();++j) {
            auto largestPalindromLen = 1;
            auto highLocal = s.length()-1;
            auto found = false;
            //cout << s[j] << ", "<<charIndexes[s[j]].size() << endl;
//             for (auto x : charIndexes[s[j]]) {
//                 cout << x << ",";
//             }
//             cout << endl;

//             cout << endl;
            for (vector<int>::reverse_iterator it = charIndexes[s[j]].rbegin(); *it>j && (*it-j+1)>largestPalindromLen;++it) {
                //cout << "For " << j << "," << *it << endl;
                if (checkPalindrome(j,*it)) {
                    //cout << "Palindome " << j << "," << *it << endl;
                    largestPalindromLen = (*it-j+1);
                    highLocal = *it;
                    found = true;
                    break;
                }

            }

            if (found && largestPalindromLen > maxLen) {
                //cout << "Found " << j << "," << highLocal << endl;
                low = j;
                high = highLocal;
                maxLen = largestPalindromLen;
            }

        }

        return s.substr(low,high-low+1);
    }
};
