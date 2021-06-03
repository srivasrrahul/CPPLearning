//
// Created by Srivastava, Rahul on 01/06/21.
//
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
    unordered_map<int,int> valLocation;
    vector<int> values;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valLocation.find(val) == valLocation.end()) {
            values.push_back(val);
            valLocation[val] = values.size()-1;
            return true;
        }else {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valLocation.find(val) != valLocation.end()) {
            if (values.size() > 1) {
                auto last = values.back();
                auto indexOfVal = valLocation.find(val)->second;

                values[indexOfVal] = last;
                valLocation[last] = indexOfVal;

                values.pop_back();
                valLocation.erase(val);

            }else {
                values.clear();
                valLocation.clear();
            }

            return true;
        }else {
            return false;
        }


    }

    /** Get a random element from the set. */
    int getRandom() {
        return values[std::rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */