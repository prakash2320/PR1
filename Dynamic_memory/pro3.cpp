#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head; // Points to the first node

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning
    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        cout << "Inserted " << data << " at the beginning.\n";
    }

    // Search for a key in the linked list
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Found " << key << " in the list.\n";
                return true;
            }
            temp = temp->next;
        }
        cout << key << " not found in the list.\n";
        return false;
    }

    // Delete a node by key
    void delete_node(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Deleted node with key " << key << ".\n";
            return;
        }

        // Search for the key to delete
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key not found
        if (temp == nullptr) {
            cout << "Key " << key << " not found.\n";
            return;
        }

        // Remove node
        prev->next = temp->next;
        delete temp;
        cout << "Deleted node with key " << key << ".\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "Linked list reversed.\n";
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }

        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Search\n";
        cout << "3. Delete Node\n";
        cout << "4. Reverse List\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insert_at_beginning(data);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> data;
                list.search(data);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> data;
                list.delete_node(data);
                break;
            case 4:
                list.reverse();
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
