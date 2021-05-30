//
// Created by Srivastava, Rahul on 24/05/21.
//
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
#include <list>

using namespace std;

class LRUCache {

    unordered_map<int,pair<int,list<int>::iterator>>  m_Cache;
    list<int> m_LRUOrderedKeys;
    int m_Capacity;
public:
    LRUCache(int capacity) {
        m_Capacity = capacity;
    }

    void evict() {
        auto lastKey = m_LRUOrderedKeys.back();
        //cout << "last key " << lastKey << endl;
        m_LRUOrderedKeys.pop_back();
        m_Cache.erase(lastKey);
    }

    void put(int key, int value) {
        if (m_Cache.find(key) != m_Cache.end()) {
            auto keyItr = m_Cache.find(key)->second.second;
            m_LRUOrderedKeys.erase(keyItr);
            m_Cache.erase(key);
        }

        if (m_Cache.size() >= m_Capacity) {
            evict();
        }

        m_LRUOrderedKeys.push_front(key);
        m_Cache[key] = make_pair(value,m_LRUOrderedKeys.begin());
    }


    int get(int key) {
        if (m_Cache.find(key) == m_Cache.end()) {
            return -1;
        }

        auto second = m_Cache.find(key)->second;
        auto val = second.first;
        auto itr = second.second;

        m_LRUOrderedKeys.erase(itr);
        m_LRUOrderedKeys.push_front(key);

        m_Cache[key] = make_pair(val,m_LRUOrderedKeys.begin());
        return val;
    }

    void print() {

    }


};


 int main() {
    auto solution = LRUCache(2);
    solution.put(1,1);
    //solution.print();

     solution.put(2,2);
     solution.get(1);
//     solution.print();
//
     solution.put(3,3);
//     solution.print();
//     cout << solution.get(2) << endl;
//
//     solution.put(4,4);

 }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */