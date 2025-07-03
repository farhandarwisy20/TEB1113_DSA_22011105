#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(Node& node) {
        node.next = top;
        top = &node;
    }

    void pop() {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
    } else {
        Node* current = top;
        top = top->next;
    }
}


    void display_stack() {
        Node* curr = top;
        while (curr != nullptr) {
            cout << curr->name << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Alice");

    Stack stack;
    stack.push(node1);
    stack.push(node2);
    stack.push(node3);

    cout << "Initial stack:\n";
    stack.display_stack();

    stack.pop();
    cout << "After pop:\n";
    stack.display_stack();

    return 0;
}
