#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(int value) {
        root = new Node(value);
    }

    void add_left(int parent, int child) {
        Node* p = find_node(root, parent);
        if (p != nullptr) {
            p->left = new Node(child);
        }
    }

    void add_right(int parent, int child) {
        Node* p = find_node(root, parent);
        if (p != nullptr) {
            p->right = new Node(child);
        }
    }

    // Public function to find path
    bool find_path(int value, string& path) {
        path = "";
        return find_path_helper(root, value, path);
    }

private:
    Node* find_node(Node* current, int value) {
        if (current == nullptr) return nullptr;
        if (current->value == value) return current;

        Node* found = find_node(current->left, value);
        if (found != nullptr) return found;

        return find_node(current->right, value);
    }

    // Recursive helper for path finding
    bool find_path_helper(Node* current, int value, string& path) {
        if (current == nullptr) return false;
        if (current->value == value) return true;

        // Go left
        path.push_back('L');
        if (find_path_helper(current->left, value, path)) {
            return true;
        }
        path.pop_back();

        // Go right
        path.push_back('R');
        if (find_path_helper(current->right, value, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};

int main() {
    Tree tree;

    tree.add_root(50);
    tree.add_left(50, 30);
    tree.add_right(50, 70);
    tree.add_left(30, 20);
    tree.add_right(30, 40);
    tree.add_left(70, 60);
    tree.add_right(70, 80);

    int searchValue = 30;
    cout << "Searching for number: " << searchValue << endl;

    string path;
    if (tree.find_path(searchValue, path)) {
        cout << searchValue << " exists in the tree." << endl;
        cout << "Path from root: Root";
        for (char c : path) {
            cout << " -> " << (c == 'L' ? "Left" : "Right");
        }
        cout << endl;
    } else {
        cout << searchValue << " does NOT exist in the tree." << endl;
    }

    return 0;
}
