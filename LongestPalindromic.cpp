//
// Created by Srivastava, Rahul on 06/06/21.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
class Decision {
private:
    int m_Low;
    int m_High;
public:
    Decision(int mLow, int mHigh) : m_Low(mLow), m_High(mHigh) {}

    int getMLow() const {
        return m_Low;
    }

    int getMHigh() const {
        return m_High;
    }

    bool operator==(const Decision &rhs) const {
        return m_Low == rhs.m_Low &&
               m_High == rhs.m_High;
    }

    bool operator!=(const Decision &rhs) const {
        return !(rhs == *this);
    }


};

struct Hash {
    size_t operator()(const Decision & d) const {
        return d.getMLow()+d.getMHigh();
    }
};
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp;
        for (int j = 0;j<s.length();++j) {
            dp.push_back(vector<int>{});
            for (int k = 0;k<s.length();++k) {
                if (j == k) {
                    dp[j].push_back(1);
                }else {
                    dp[j].push_back(0);
                }
            }
        }

        auto colStarter = 1;
        int j = 0;
        int k = colStarter;

        auto maxLen = 1;
        while (j < s.length() && k < s.length()) {
            if (j+1 == k) {
                if (s[j] == s[k]) {
                    dp[j][k] = 2;;
                }else {
                    dp[j][k] = 0;
                }
            }else {
                if (dp[j+1][k-1] > 0) {
                    if (s[j] == s[k]) {
                        dp[j][k] = dp[j+1][k-1]+2;
                    }else {
                        dp[j][k] = 0;
                    }
                }else {
                    dp[j][k] = 0;
                }
            }

            maxLen = max(maxLen,dp[j][k]);

            j = j+1;
            k = k+1;
            if (k >= s.length()) {
                colStarter++;
            }

            if (j >= s.length() || k >= s.length()) {
                j = 0;
                k = colStarter;
            }
        }

        for (int j = 0;j<s.length();++j) {
            for (int k = j;k<s.length();++k) {
                if (dp[j][k] == maxLen) {
                    return s.substr(j,maxLen);
                }
            }
        }

        return 0;

    }
};
