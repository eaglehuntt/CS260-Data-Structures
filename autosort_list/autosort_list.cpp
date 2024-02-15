#include <iostream>
#include <string>
#include "./autosort_list.hpp"

// private 

void AutosortList::set_head(Node *new_head){
    this->head = new_head;
};

void AutosortList::set_tail(Node *new_tail){
    this->tail = new_tail;
};

// public

AutosortList::AutosortList(){
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
};

void AutosortList::push(int value){
    Node *new_node = new Node(value);
    // std::cout << "pushing " << value << " to the list" << std::endl;

    if (this->head == nullptr) {
        // std::cout << "Pushing initial value to list" << std::endl;
        this->head = new_node;
        this->tail = new_node;
    } else {
        Node *prev = nullptr;
        Node *current = this->head;

        while (current != nullptr && value > current->get_value()) {
            // std::cout << "iterating though mid, val: " << current->get_value() << std::endl;
            prev = current;
            current = current->get_next();
        }

        if (current == nullptr) {
            // std::cout << "inserting at the end" << std::endl;
            // Insert at the end
            this->tail->set_next(new_node);
            new_node->set_previous(this->tail); // double link
            this->tail = new_node;
        } else if (prev == nullptr){
            // std::cout << "inserting at the start" << std::endl;
            new_node->set_next(this->head);
            new_node->set_previous(nullptr);
            this->head->set_previous(new_node);
            this->head = new_node;
        } else {
            // std::cout << "inserting in the middle " << value << " in the list" << std::endl;
            prev->set_next(new_node);
            new_node->set_previous(prev);
            new_node->set_next(current);
            current->set_previous(new_node);
        }
    }

    // Update the tail
    if (new_node->get_next() == nullptr) {
        // std::cout << "updating the tail" << std::endl;
        this->tail = new_node;
    }

    this->size++;

    // Update each node's index
    Node *current = this->head;
    for (int i = 0; i < this->size; i++){
        current->set_index(i);
        current = current->get_next();
    }
}


void AutosortList::pop(){
    // std::cout << "popping last node" << std::endl;

    if (this->size == 0){
        std::cout << "list is empty! cannot pop" << std::endl;
        return;
    } else if (this->head == this->tail){
        // std::cout << "deleting the head and tail" << std::endl;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        // std::cout << "deleting just the tail " << std::endl;
        Node *old_tail = this->tail;
        this->tail = old_tail->get_previous();
        this->tail->set_next(nullptr);
        delete old_tail;

        if (this->tail == nullptr) {
            this->head = nullptr; // Update head if the list becomes empty
        }
    }
    this->size--;
    // std::cout << "popped the last node from the list" << std::endl;
};


int AutosortList::get_value_at_index(int index){

    if (index >= 0 && index < this->size){

        if (index <= this->size / 2) {
            Node *current = this->head;
            for (int i = 0; i < index; i++) {
                current = current->get_next(); // walk through the list of nodes
            }
            return current->get_value();

        } else {
            Node *current = this->tail;
            for (int i = this->size - 1; i > index; i--) {
                current = current->get_previous(); // walk through the list of nodes
            }
            return current->get_value();
        }
    } else {
        std::cout << "Index out of bounds" << std::endl;
        return -1;
    }
}

int AutosortList::get_size(){
    return this->size;
};

Node* AutosortList::get_head(){
    return this->head;
}

Node* AutosortList::get_tail(){
    return this->tail;
}

void AutosortList::print(){
    std::string representation = "[";

    Node* current = this->head;
    
    if (this->head == nullptr){
        std::cout << "[]" << std::endl;
    }
    else {
        while (current != nullptr) {
            if (current->get_index() == 0){
                representation += std::to_string(current->get_value());
            } else {
                representation += + ", " +std::to_string(current->get_value());
            }
            // std::cout << current->get_value() << std::endl;
            current = current->get_next(); // walk through the list of nodes
        }
        representation += "]";
        std::cout << representation << std::endl;
    }
}