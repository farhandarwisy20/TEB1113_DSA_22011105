#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
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

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(string parent, string child) {
        Node* p = find_node(root, parent);
        if (p != nullptr) {
            p->left = new Node(child);
        } 
    }

    void add_right(string parent, string child) {
        Node* p = find_node(root, parent);
        if (p != nullptr) {
            p->right = new Node(child);
        } 
    }

private:
    Node* find_node(Node* current, string name) {
        if (current == nullptr) return nullptr;
        if (current->name == name) return current;

        Node* found = find_node(current->left, name);
        if (found != nullptr) return found;

        return find_node(current->right, name);
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of C: " << tree.root->right->left->name << endl;
    cout << "Right child of C: " << tree.root->right->right->name << endl;

    return 0;
}
