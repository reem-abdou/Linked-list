#include <iostream> 

using namespace std; 

// Create a node which contains data value and a pointer and make it public to can access
class Node { 
public: 
    int data;
    Node* next; 
}; 

class Linkedlist { 
public: 
    Node* head; // Create a pointer of type Node to point at the first item in the list 

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
        newnode->next = head; // Point the new node's next to head (to point to the previous item)
        head = newnode; // Make head point to the first item 
    } 

    void insertbeforeitem(int newvalue, int item) {
        if (empty()) {
            cout << "The list is empty";
        }
        else if (head->data == item) { // Insert at the beginning
            Node* newnode = new Node(); // Create a new node
            newnode->data = newvalue;  // Set the data for the new node
            newnode->next = head;
            head = newnode;
        }
        else if (isfound(item)) {  // Check if the item exists in the linked list
            Node* newnode = new Node(); // Create a new node
            newnode->data = newvalue;  // Set the data for the new node
            Node* prev = head;    // Create a pointer points to the first item
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
            Node* temp = head; // Create a template pointer points to the first item
            while (temp->next != NULL) { // Make temp pointer points to the last item
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Create method to Display items in the list
    void Display() { 
        Node* temp = head; // Create a template pointer points to the first item
        while (temp != NULL) { // Loop until the end of the list
            cout << temp->data << " "; 
            temp = temp->next; // Move to the next node
        } 
        cout << '\n';
    } 

    // Create method to check if a value is found or not
    bool isfound(int x) { 
        Node* temp = head; // Create a template pointer points to the first item
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
    
    // Method to delete an 'item' from the list
    void Delete(int item) {
        if (empty()) {
            cout << "The List is empty, no items to delete \n";
            return;
        }
        else if (!isfound(item)) {
            cout << "This item is not found\n";
            return;
        }
        else if (head->data == item) {
            Node* delptr = head;
            head = head->next;
            delete delptr;   // Delete the Node
            return;
        }
        else {
            Node* prev = NULL;
            Node* delptr = head;
            while (delptr->data != item) {
                prev = delptr;          // Make prev points to the previous node 
                delptr = delptr->next;  // Make delptr points to the node that will be deleted
            }
            prev->next = delptr->next;  // Make the previous node points to the following node 
            delete delptr;   // Delete the Node
        }
    }
    
    // Method to deallocate the memory to prevent memory leak
    void finish(){
        while(head != NULL) { // Loop until the end of the list
            Node* temp = head; // Create a template pointer points to the first item
            head = head->next; // Move to the next node
            delete temp;  
        } 
    }
}; 

int main() { 
    Linkedlist lst;
    int newitem;
   
    if (lst.empty()) {
        cout << "The list is empty! \n";
    }
   
    int num;
    cout << "Enter the number of items you want to add: \n";
    cin >> num;
   
    cout << "Please enter the items, separating each with a space: \n";
    for (int i = 0; i < num; i++) {  
        cin >> newitem; 
        lst.append(newitem); 
    } 

    cout << "Your list is: \n";
    lst.Display(); 
   
    cout << "Enter a value that you want to append: \n";
    cin >> newitem;
    lst.append(newitem); 
   
    cout << "The New item is added successfully \n"
         << "Your New list is: \n";
    lst.Display();
   
    cout << "Insert an item at the beginning of the list: \n";
    cin >> newitem;
    lst.insertbegin(newitem); 
   
    cout << "The New item is added successfully \n"
         << "Your New list is: \n";
    lst.Display();
   
    int place;
    cout << "Add new value before a specific item \n";
    cout << "Enter the new value: \n";
    cin >> newitem;
    cout << "Enter the item you want to add before: \n";
    cin >> place; 
    lst.insertbeforeitem(newitem, place);
 
    if(lst.isfound(newitem)) {
        cout << "The New item is added successfully \n"
             << "Your New list is: \n";
        lst.Display();
    }
   
    int item;
    cout << "Enter a value that you want to delete: \n";
    cin >> item;
    lst.Delete(item);
   
    if (!lst.isfound(item)) {
        cout << "The item has been deleted successfully \n"
             << "Your New list is: \n";
        lst.Display();
    }
   
    int x;
    cout << "Enter a value to check: \n";
    cin >> x; 
    if (lst.isfound(x)) {
        cout << "It is found \n";
    }
    else {
        cout << "It is not found \n";
    }
    
    lst.finish();
    if (lst.empty()) {
        cout << "The program is finished and the list is empty! \n";
    }
    
    return 0; 
}
