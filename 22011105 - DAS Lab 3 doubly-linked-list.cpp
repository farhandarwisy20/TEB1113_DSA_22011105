#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
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
            node.prev = curr;
        }
        node.next = nullptr;
    }

    void display_list_forward() {
        Node* curr = head;
        cout << "Forward: ";
        while (curr != nullptr) {
            cout << curr->name << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void display_list_backward() {
        if (!head) return;

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        cout << "Backward: ";
        while (curr != nullptr) {
            cout << curr->name << " <-> ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
    }

    void delete_value(string name) {
        Node* curr = head;

        while (curr != nullptr && curr->name != name) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Name not found: " << name << endl;
            return;
        }

        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        cout << "Deleted: " << name << endl;
    }
};

int main() {
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Alice");

    DoublyLinkedList std_list;
    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Initial list:\n";
    std_list.display_list_forward();
    std_list.display_list_backward();

    std_list.delete_value("Ahmed");

    cout << "\nAfter deletion:\n";
    std_list.display_list_forward();
    std_list.display_list_backward();

    return 0;
}
