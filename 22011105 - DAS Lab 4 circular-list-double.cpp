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
            node.next = head; 
            node.prev = head; 
        } else {
            Node* last = head->prev;  
            last->next = &node;
            node.prev = last;
            node.next = head;
            head->prev = &node;
        }
    }

   void display_list_forward() {
    if (head == nullptr) {
        cout << "Forward: List is empty." << endl;
        return;
    }

    cout << "Forward: ";
    Node* curr = head;
    do {
        cout << curr->name << " <-> ";
        curr = curr->next;
    } while (curr != head);
    cout << head->name << endl; 
  }

 void display_list_backward() {
    if (head == nullptr) {
        cout << "Backward: List is empty." << endl;
        return;
    }

    Node* last = head->prev;
    cout << "Backward: ";
    Node* curr = last;
    do {
        cout << curr->name << " <-> ";
        curr = curr->prev;
    } while (curr != last);
    cout << last->name << endl; 
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

    return 0;
}
