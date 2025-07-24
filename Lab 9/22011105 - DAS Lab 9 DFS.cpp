#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>

using namespace std;

void addEdge(unordered_map<string, vector<string>>& graph, const string& from, const string& to) {
    graph[from].push_back(to);
}

void DFS(const unordered_map<string, vector<string>>& graph, const string& current, set<string>& visited) {
    visited.insert(current);
    cout << current << " ";

    if (graph.find(current) != graph.end()) {
        for (const string& neighbor : graph.at(current)) {
            if (!visited.count(neighbor)) {
                DFS(graph, neighbor, visited);
            }
        }
    }
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

    set<string> visited;
    cout << "DFS starting from A: ";
    DFS(graph, "A", visited);

    cout << endl;
    return 0;
}


