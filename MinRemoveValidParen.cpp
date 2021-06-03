//
// Created by Srivastava, Rahul on 31/05/21.
//
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
class Tuple {
    char m_Ch;
    int m_Index;
public:
    Tuple(char mCh, int mIndex) : m_Ch(mCh), m_Index(mIndex) {}

    char getCh() const {
        return m_Ch;
    }

    int getIndex() const {
        return m_Index;
    }
};
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<Tuple> brackets;
        for (int j = 0;j<s.length();++j) {
            if (s[j] == '(' || s[j] == ')') {
                brackets.push_back(Tuple(s[j],j));
            }
        }

        unordered_set<int> removalIndex;

        stack<Tuple> st;
        for (auto t : brackets) {
            switch (t.getCh()) {
                case '(' : {
                    st.push(t);
                    break;
                }
                case ')' : {
                    if (st.empty()) {
                        removalIndex.insert(t.getIndex());
                    }else {
                        st.pop();
                    }
                    break;
                }
            }
        }

        while (st.empty() == false) {
            removalIndex.insert(st.top().getIndex());
            st.pop();
        }

        string retValue;
        for (int j = 0;j<s.size();++j) {
            if (removalIndex.find(j) == removalIndex.end()) {
                retValue.push_back(s[j]);
            }
        }

        return retValue;
    }
};

