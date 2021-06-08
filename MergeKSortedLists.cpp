//
// Created by Srivastava, Rahul on 08/06/21.
//

#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class EntryNode {
    int m_Index;
    int m_LocalIndex;
    ListNode * m_Node;
public:
    EntryNode(int mIndex, int mLocalIndex, ListNode *mNode) : m_Index(mIndex), m_LocalIndex(mLocalIndex),
                                                              m_Node(mNode) {}

    int getIndex() const {
        return m_Index;
    }

    int getLocalIndex() const {
        return m_LocalIndex;
    }

    ListNode *getNode() const {
        return m_Node;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode * l1, const ListNode * l2) {
            return l1->val > l2->val;
        };

        priority_queue<ListNode*,vector<ListNode*>, decltype(comp)> pq(comp);

        ListNode * head = nullptr;
        ListNode * itr = nullptr;

        for (int j = 0;j<lists.size();++j) {
            auto ptr = lists[j];
            if (ptr != nullptr) {
                pq.push(ptr);
            }

        }

        while (pq.empty() == false) {
            auto top = pq.top();
            pq.pop();
            //cout<<top->val << endl;

            auto next = top->next;
            if (head == nullptr) {
                head = top;
                itr = top;
            }else {
                itr->next = top;
                itr = itr->next;
            }

            itr->next = nullptr;
            if (next != nullptr) {
                pq.push(next);
            }

        }

        return head;


    }
};