//
// Created by Srivastava, Rahul on 16/05/21.
//
#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string retValue;
        for (auto ch : address) {
            if (ch == '.') {
                retValue.append("[.]");
            }else {
                retValue.push_back(ch);
            }
        }

        return retValue;
    }
};

int main() {
    auto s = new Solution();
    cout << s->defangIPaddr("1.2.3.4") << endl;
}