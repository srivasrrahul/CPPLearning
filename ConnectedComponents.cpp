//
// Created by Srivastava, Rahul on 03/05/21.
//

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
class Node {
private :
    unordered_set<int> next;
public:
    void addNext(int v) {
        next.insert(v);
    }

    const unordered_set<int> & getNeighbours() {
        return next;
    }
};
class Graph {
private:
    vector<Node> nodes;
public:
    Graph(int n) {
        for (int j= 0;j<n;j++) {
            nodes.push_back(*new Node());
        }
    }

    void add(int u,int v) {
        nodes[u].addNext(v);
        nodes[v].addNext(u);
    }

    const Node & getNode(int u) {
        return nodes[u];
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        auto graph = Graph(n);
        for (auto edge : edges) {
            graph.add(edge[0],edge[1]);
        }

        auto bfs = [&](int sourceNode) {
            unordered_set<int> visited ;
            queue<int> q;
            q.push(sourceNode);

            while (q.empty() == false) {
                auto top = q.front();
                q.pop();
                visited.insert(top);
                auto next = graph.getNode(top);
                for (auto n : next.getNeighbours()) {
                    if (visited.find(n) == visited.end()) {
                        q.push(n);
                    }
                }
            }

            return visited;
        };

        unordered_set<int> globalVisited;
        auto connectComponents = 0;
        for (int j = 0;j<n;++j) {
            if (globalVisited.find(j) == globalVisited.end()) {
                auto res = bfs(j);
                globalVisited.insert(res.begin(),res.end());
                connectComponents++;
            }
        }

        return connectComponents;
    }
};

int main() {

}
