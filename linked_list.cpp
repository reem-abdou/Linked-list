#include <iostream> 

using namespace std; 

// Creat a node which contains data value and a pointer and make it public to can acces
class Node { 
public: 
    int data;
    Node* next; 
}; 

class Linkedlist { 
public: 
    Node* head; // Creat a pointer of type Node to point at the first item in the list 

    Linkedlist() { 
        head = NULL; // The list is initially empty
    } 

    bool empty() { 
        return (head == NULL); // Method to check if the list is empty or not
    } 

    // Method to add node in the beginning of the list
    void insertbegin(int newitem) { 
        Node* newnode = new Node; // Create a new node
        newnode->data = newitem; // Set the data for the new node
        newnode->next = head; // Point the new node's next to head (to points to the previous item)
        head = newnode; // Make haed points to the first item 
    } 

    // Creat method to Display items in the list
    void Display() { 
        Node* temp = head; // Creat a template pointer points to the first item
        while (temp != NULL) { // Loop until the end of the list
            cout << temp->data << " "; 
            temp = temp->next; // Move to the next node
        } 
        cout << '\n';
    } 

    // Creat method to check if a value is found or not
    bool isfound(int x) { 
        Node* temp = head; // Creat a template pointer points to the first item
        bool F = false; // Flag to indicate if the item is found and set it = false by default
        while (temp != NULL) { // Loop until the end of the list
            if (temp->data == x) { 
                F = true;   // Set flag to true if the value is found
                break;  
            } 
            temp = temp->next; // Move to the next node
        } 
        return F; // Return flag
    } 

    void insertbeforeitem(int newvalue, int item) {
        if (empty()) {
            cout << "The list is empty";
            return;
        }
        else if (head->data == item) { // Insert at the beginning
            Node* newnode = new Node(); // Create a new node
            newnode->data = newvalue;  // Set the data for the new node
            newnode->next = head;
            head = newnode;
            return;
        }
        else if (isfound(item)) {  // Check if the item exists in the linked list
            Node* newnode = new Node(); // Create a new node
            newnode->data = newvalue;  // Set the data for the new node
            Node* prev = head;    // Creat a pointer points to the first item
            // Make previous pointer points to the node before the 'item' node
            while (prev != NULL && prev->next->data != item) {
                prev = prev->next;  // Move to the next node
            }
            newnode->next = prev->next;  // Link the new node to the 'item' node
            prev->next = newnode;      // Link the previous node to the new node
        }
        else {
            cout << "Item is not found \n";
        }
    }
    
    // Method to append a new node at the end of the linked list
    void append(int newvalue) {
        Node* newnode = new Node(); // Create a new node
        newnode->data = newvalue;  // Set the data for the new node
        if (empty()) {
            head = newnode; // Make head points to the first item
        }
        else {
            Node* 
