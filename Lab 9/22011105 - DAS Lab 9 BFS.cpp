#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

void addEdge(unordered_map<string, vector<string>>& graph, const string& from, const string& to) {
    graph[from].push_back(to);
}

void BFS(const unordered_map<string, vector<string>>& graph, const string& start) {
    set<string> visited;
    queue<string> q;

    visited.insert(start);
    q.push(start);

    cout << "BFS starting from " << start << ": ";

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        cout << current << " ";

        if (graph.find(current) != graph.end()) {
            for (const string& neighbor : graph.at(current)) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

    cout << endl;
}

int main() {
    unordered_map<string, vector<string>> graph;

    addEdge(graph, "A", "B");
    addEdge(graph, "B", "E");
    addEdge(graph, "A", "D");
    addEdge(graph, "A", "C");
    addEdge(graph, "C", "D");
    addEdge(graph, "D", "E");
    addEdge(graph, "B", "D");

    BFS(graph, "A");

    return 0;
}


