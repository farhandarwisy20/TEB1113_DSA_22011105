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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void add_item(Node& node) {
        if (head == nullptr) {
            head = &node;
            node.next = head;  
        } else {
            Node* curr = head;
            while (curr->next != head) {  
                curr = curr->next;
            }
            curr->next = &node;
            node.next = head;  
        }
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->name << " -> ";
            curr = curr->next;
        } while (curr != head);

        cout << head->name << endl;  
    }
};

int main() {
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Alice");

    LinkedList std_list;
    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Initial list:\n";
    std_list.display_list();

    return 0;
}
