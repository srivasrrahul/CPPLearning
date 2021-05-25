//
// Created by Srivastava, Rahul on 23/05/21.
//

#include <iostream>
#include <utility>
#include <functional>


using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            if (l1 == nullptr) {
                return l2;
            }else {
                return l1;
            }
        }

        const std::function< ListNode* (ListNode *, ListNode *,int)> sumTwo =
                [& sumTwo](ListNode * p1,ListNode * p2,int carry) {
                    if (p1 == nullptr && p2 == nullptr) {
                        if (carry == 0) {
                            return (ListNode *)nullptr;
                        }

                        return new ListNode(carry);
                    }else {
                        if (p1 == nullptr) {
                            auto newSum = (carry + p2->val)%10;
                            auto newCarry = (carry + p2->val)/10;
                            auto nextNode =  sumTwo(p1,p2->next,newCarry);
                            return new ListNode(newSum,nextNode);
                        }else {
                            if (p2 == nullptr) {
                                auto newSum = (carry + p1->val)%10;
                                auto newCarry = (carry + p1->val)/10;
                                auto nextNode =  sumTwo(p1->next,p2,newCarry);
                                return new ListNode(newSum,nextNode);
                            }else {
                                auto newSum = (carry + p1->val+p2->val)%10;
                                auto newCarry = (carry + p1->val + p2->val)/10;
                                auto nextNode =  sumTwo(p1->next,p2->next,newCarry);
                                return new ListNode(newSum,nextNode);
                            }
                        }
                    }
                };

        return sumTwo(l1,l2,0);
    }
};

int main() {

}
