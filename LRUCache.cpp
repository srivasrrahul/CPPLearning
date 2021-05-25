//
// Created by Srivastava, Rahul on 24/05/21.
//
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
using namespace std;

class LRUCache {
    unordered_map<int,pair<int,int> > m_Cache;
    map<int,int> m_TimedUsage;
    int m_Capacity;
    int m_Time;
public:
    LRUCache(int capacity) {
        m_Capacity = capacity;
        m_Time = 0;
    }

    void evict() {
        auto last = m_TimedUsage.begin();
        auto lastKey = last->second;
        auto lastTime = last->first;
        m_Cache.erase(lastKey);
        m_TimedUsage.erase(lastTime);
        cout << "evicted " << lastKey << endl;
    }

    void put(int key, int value) {
        cout << "put " << key << ":" << value << endl;
        m_Time++;
        if (m_Cache.find(key) == m_Cache.end()) {
            //doesn't find

            //no capacity
            if (m_Cache.size() >= m_Capacity) {
                evict();

            }

            m_Cache[key] = make_pair(value,m_Time);
            m_TimedUsage[m_Time] = key;
        }else {
            auto current = m_Cache.find(key)->second;
            auto lastTime = current.second;

            m_Cache[key] = make_pair(value,m_Time);

            m_TimedUsage.erase(lastTime);
            m_TimedUsage[m_Time] = key;
        }
    }


    int get(int key) {
        cout << "get " << key << endl;
        m_Time++;
        if (m_Cache.find(key) == m_Cache.end()) {
            return -1;
        }

        auto current = m_Cache.find(key)->second;
        m_Cache[key] = make_pair(current.first,m_Time);
        m_TimedUsage.erase(current.second);
        m_TimedUsage[m_Time] = key;

        return current.first;

    }

    void print() {
        cout << "************************************************" << endl;
        for (auto & kv : m_Cache) {

            cout << kv.first << " => " << kv.second.first << ", time " <<  kv.second.second << endl;
        }

        cout << "=============" << endl;

        for (auto &kv : m_TimedUsage) {
            cout << kv.first << " => " << kv.second << endl;
        }
    }


};


 int main() {
    auto solution = LRUCache(2);
    solution.put(1,1);
    //solution.print();

     solution.put(2,2);
     solution.get(1);
     solution.print();

     solution.put(3,3);
     solution.print();
     cout << solution.get(2) << endl;

     solution.put(4,4);

 }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */