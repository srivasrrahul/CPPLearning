//
// Created by Srivastava, Rahul on 07/06/21.
//

#include <unordered_map>
#include <vector>
#include <map>
#include <set>


using namespace std;
typedef unsigned int ID;
typedef unsigned int VALUE;
typedef unsigned int COUNTER;
typedef unsigned int ACCESS_TIME;
class AssociatedData {
private:
    VALUE m_Value;
    COUNTER m_Counter;
    ACCESS_TIME m_AccessTime;
public:
    AssociatedData() {
        m_Value = 0;
        m_Counter = 0;
        m_AccessTime = 0;

    }
    AssociatedData(VALUE mValue, COUNTER mCounter, ACCESS_TIME mAccessTime) : m_Value(mValue), m_Counter(mCounter),
                                                                              m_AccessTime(mAccessTime) {}

    VALUE getValue() const {
        return m_Value;
    }

    COUNTER getCounter() const {
        return m_Counter;
    }

    ACCESS_TIME getAccessTime() const {
        return m_AccessTime;
    }
};
class LFUCache {
    unordered_map<ID,AssociatedData> m_Value;
    map<COUNTER,map<ACCESS_TIME,ID>> m_LFUOrder;

    int m_Time;
    int m_Capacity;

public:
    LFUCache(int capacity) {
        m_Time = 1;
        m_Capacity = capacity;
    }

    int get(int key) {
        ++m_Time;
        if (m_Value.find(key) != m_Value.end()) {
            auto associatedData = m_Value.find(key)->second;
            removeId(key);


            auto existingCounter = associatedData.getCounter();
            auto newCounter = existingCounter+1;

            AssociatedData newAssocData(associatedData.getValue(),newCounter,m_Time);

            insert(key,newAssocData);
            return newAssocData.getValue();

        }else {
            return -1;
        }
    }

    void removeId(ID id) {
        auto assocData = m_Value[id];

        m_LFUOrder[assocData.getCounter()].erase(assocData.getAccessTime());
        if (m_LFUOrder[assocData.getCounter()].size() == 0) {
            m_LFUOrder.erase(assocData.getCounter());
        }

        m_Value.erase(id);

    }
    void evict() {
        //LFU Order
        removeId(m_LFUOrder.begin()->second.begin()->second);

    }
    void insert(int key,AssociatedData associatedData) {
        m_Value[key] = associatedData;
        m_LFUOrder.emplace(associatedData.getCounter(),map<ACCESS_TIME,ID>{});
        (m_LFUOrder[associatedData.getCounter()])[associatedData.getAccessTime()] = key;
    }

    void put(int key, int value) {
        m_Time++;
        if (m_Value.find(key) != m_Value.end()) {
            auto associatedData = m_Value[key];
            removeId(key);

            auto newCounter = associatedData.getCounter()+1;
            auto newAssocData = AssociatedData(value,newCounter,m_Time);
            insert(key,newAssocData);

        }else {
            if (m_Capacity == 0) {
                return;
            }

            if (m_Value.size() >= m_Capacity) {
                evict();
            }
            AssociatedData associatedData(value,1,m_Time);
            insert(key,associatedData);
        }
    }
};

