//
// Created by Srivastava, Rahul on 16/05/21.
//

#include <unordered_set>
#include <list>
#include <iostream>

using namespace std;
class Solution {
public:
    int findTheWinner(int n, int K) {
        std::list<int> friends;
        for (int j = 1;j<=n;++j) {
            friends.push_back(j);
        }

        list<int>::iterator itr = friends.begin();
        while (friends.size() > 1) {
            cout << "starting at " << *itr << endl;
            for (int c = 1; c <K;c++) {
                if (itr == friends.end()) {
                    itr = friends.begin();
                }

                ++itr;
            }

            if (itr == friends.end()) {
                itr = friends.begin();
            }

            cout << "removing " << *itr << endl;
            list<int>::iterator itr1 = itr;
            ++itr1;
            friends.erase(itr);
            itr = itr1;

        }

        return friends.front();
    }
};

int main() {
    auto s = new Solution();
    cout << s->findTheWinner(6,5);
}