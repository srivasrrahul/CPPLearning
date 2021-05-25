//
// Created by Srivastava, Rahul on 03/05/21.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class TrieRoot {

};

class TrieNode {
private :
    unordered_map<char,pair<TrieNode *,bool> > next;
public:
    void add(const string & str,int index) {
        auto fullString = false;
        if (index == str.length()-1) {
            fullString = true;
        }
        if (index == str.length()) {

        }else {
            if (next.find(str[index]) == next.end()) {
                auto newNode = new TrieNode();
                next.insert({str[index],make_pair(newNode,fullString)});
                newNode->add(str,index+1);
            }else {
                auto nextTrieNode = next.find(str[index])->second.first;
                nextTrieNode->add(str,index+1);
            }
        }
    }

    TrieNode * prefix(const string & str,int index) {
        if (index == str.length()) {
            return NULL;
        }else {
            if (next.find(str[index]) == next.end()) {
                return NULL;
            }else {
                auto retValue = next.find(str[index]);
                if (index == str.length()-1) {
                    return retValue->second.second?retValue->second.first:NULL;
                }else {
                    return retValue->second.first->prefix(str,index+1);
                }
            }
        }
    }

};
class WordFilter {
    TrieNode prefixTrieNode;
    TrieNode suffixTrieNode;
public:
    WordFilter(vector<string>& words) {
       for (auto word : words) {
           prefixTrieNode.add(word,0);
           suffixTrieNode.add(string(word.rbegin(),word.rend()),0);
       }
    }

    int f(string prefix, string suffix) {
        TrieNode * prefixTrie = prefixTrieNode.prefix(prefix,0);
        TrieNode * suffixTrie = suffixTrieNode.prefix(suffix,0);
        if (prefixTrie == NULL || suffixTrie == NULL) {
            return -1;
        }else {
            
        }
    }
};