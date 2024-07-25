#include "linkedlist.h"
#include <stdexcept>

// Constructor for the singly linked list
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor for the singly linked list
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    // Continuously pop the front item until the list is empty.
    while (!empty()) {
        pop_front();
    }
}

// add an item to the front of the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    // Create a new node and set it as the head. If the list was empty, also set it as the tail.
    head = new Node(item, head);
    if (tail == nullptr) {
        tail = head;
    }
    ++num_items; 
}

// Add an item to the end of the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item); 
    if (tail != nullptr) {
        tail->next = new_node; // If the list is not empty, append the new node at the end
    } else {
        head = new_node; // If the list is empty, set the new node as the head
    }
    tail = new_node; 
    ++num_items; 
}

// Remove an item from the front of the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty"); // Throw an exception if the list is empty
    }
    Node* old_head = head; // Temporarily store the current head
    head = head->next; // Move the head to the next node
    if (head == nullptr) {
        tail = nullptr; // If the list becomes empty, set the tail to nullptr.
    }
    delete old_head; 
    --num_items; 
}

// Remove an item from the end of the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty"); 
    }
    if (head == tail) {
        // If there's only one node, delete it and set both head and tail to nullptr.
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        // Traverse the list to find the node before the tail.
        while (current->next != tail) {
            current = current->next;
        }
        delete tail; 
        tail = current; 
        tail->next = nullptr; 
    }
    --num_items; 
}

// Get the front item of the list.
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        throw std::out_of_range("List is empty"); 
    }
    return head->data;
}

// get the back item of the list.
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        throw std::out_of_range("List is empty"); 
    }
    return tail->data; 
}

// check if the list is empty.
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr; // Return true if the head is nullptr, indicating the list is empty.
}

// Insert an item at a specific index in the list.
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index == 0) {
        push_front(item); 
    } else if (index >= num_items) {
        push_back(item);
    } else {
        Node* current = head;
       
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        current->next = new Node(item, current->next);
        ++num_items; 
    }
}

// Remove an item at a specific index in the list.
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false; // Return false if index is out of range.
    }
    if (index == 0) {
        pop_front(); 
    } else {
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        Node* old_node = current->next; 
        current->next = old_node->next; 
        if (old_node == tail) {
            tail = current; 
        }
        delete old_node; 
        --num_items; 
    }
    return true; 
}

// Find the index of an item in the list.
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head; 
    size_t index = 0;
    
    while (current != nullptr) {
        if (current->data == item) {
            return index; 
        }
        current = current->next;
        ++index;
    }
    return num_items; 
}