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
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = &node;
        }
        node.next = nullptr;
    }

    void display_list() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void delete_value(string name) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Name not found: " << name << endl;
            return;
        }

        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        cout << "Deleted: " << name << endl;
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

    std_list.delete_value("Ahmed");

    cout << "After deletion:\n";
    std_list.display_list();

    return 0;
}
