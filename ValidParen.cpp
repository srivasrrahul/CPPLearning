//
// Created by Srivastava, Rahul on 27/05/21.
//

#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto result = true;
        for (auto ch : s) {
            if (result == false) {
                break;
            }

            switch (ch) {
                case '(' : {
                    st.push(ch);
                    break;
                }
                case '[' : {
                    st.push(ch);
                    break;
                }
                case '{' : {
                    st.push(ch);
                    break;
                }
                case '}' : {
                    if (st.empty()) {
                        result = false;
                        break;
                    }

                    if (st.top() != '{') {
                        result = false;
                        break;
                    }

                    st.pop();
                }
                case ')' : {
                    if (st.empty()) {
                        result = false;
                        break;
                    }

                    if (st.top() != '(') {
                        result = false;
                        break;
                    }

                    st.pop();
                }
                case ']' : {
                    if (st.empty()) {
                        result = false;
                        break;
                    }

                    if (st.top() != '[') {
                        result = false;
                        break;
                    }

                    st.pop();
                }
            }
        }

        if (st.size() > 0) {
            result = false;
        }

        return result;
    }
};

int main() {

}