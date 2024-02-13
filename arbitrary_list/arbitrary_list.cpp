#include <iostream>

#include "./arbitrary_list.hpp"

// private 

void ArbitraryList::set_head(Node *new_head){
    this->head = new_head;
};

void ArbitraryList::set_tail(Node *new_tail){
    this->tail = new_tail;
};

// public

ArbitraryList::ArbitraryList(){
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
};

void ArbitraryList::push(int value){
    Node *new_node = new Node(value); // index is set to 0 by default
    new_node->set_index(this->size); // the index of the new node will be the size of the list

    if (this->head == nullptr){
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->set_next(new_node);
        new_node->set_previous(this->tail); // the previous node of the new node will be the tail of the list
        this->tail = new_node;
    }
    this->size++;

    // std::cout << "pushed " << value << " to the list" << std::endl;
};

void ArbitraryList::pop(){
    if (this->head != nullptr){
        Node *old_tail = this->tail;
        this->tail = old_tail->get_previous();
        this->tail->set_next(nullptr);
        delete old_tail;
        this->size--;
    }
    // std::cout << "popped the last node from the list" << std::endl;
};

void ArbitraryList::remove_at_index(int index_to_remove) {

    if (index_to_remove < 0 || index_to_remove >= this->size) {
        // If the index is out of bounds, print an error message and return 
        std::cout << "Index out of bounds, cannot remove any node" << std::endl;
        return;
    }

    if (index_to_remove == 0) {
        // If removing the first node, update the head pointer    
        Node *node_to_remove = this->head;
        this->head = node_to_remove->get_next();
        if (this->head)
            this->head->set_previous(nullptr);
        delete node_to_remove;
        this->size--;

    } else if (index_to_remove == this->size - 1) {
        // If removing the last node, update the tail pointer
        this->pop();
    } else {
        // std::cout << "Removing node at index " << index_to_remove << std::endl;
        // If removing a node other than the first or last, traverse the list to find the node to remove
        Node *current = this->head;

        // Traverse the list until the node just before the one to be removed
        for (int i = 0; i < index_to_remove - 1; i++) {
            current = current->get_next();
        }

        // specific names for easier readability. Naming things is hard

        Node *node_before = current; 
        Node *node_to_remove = node_before->get_next();
        Node *node_after = node_to_remove->get_next();

        // Update the next pointer of the preceding node to skip over the node to be removed
        node_before->set_next(node_after);

        // If there's a node after the one being removed
        if (node_after != nullptr)
            // Update the previous pointer of the node after the one being removed
            node_after->set_previous(node_before);

        delete node_to_remove;

        // Update the indices of following nodes
        int new_index = index_to_remove;
        while (node_after != nullptr) {
            node_after->set_index(new_index);
            node_after = node_after->get_next();
            new_index++;
        } 
        this->size--;
    }
    
}

void ArbitraryList::insert_at_index(int index_to_insert, int value){

    if (index_to_insert < 0 || index_to_insert > this->size) {
        // If the index is out of bounds, print an error message and return 
        std::cout << "Index out of bounds, cannot insert any node" << std::endl;
        return;
    }

    Node *new_node = new Node(value);

    if (index_to_insert == 0) {
        // Inserting at the beginning
        if (!this->head) {
            // If list is empty
            this->head = new_node;
        } else {
            Node *old_head = this->head;
            this->head = new_node;
            this->head->set_next(old_head);
            old_head->set_previous(this->head);
        }
        this->size++;
    } else if (index_to_insert == this->size) {
        this->push(value);       
    } else {
        // std::cout << "Inserting node at index " << index_to_insert << std::endl;
        // Inserting in the middle
        Node *current = this->head;
        for (int i = 0; i < index_to_insert - 1; i++) {
            current = current->get_next(); // move to the node just before the index to insert
        }

        // Adjust pointers to insert the new node
        new_node->set_next(current->get_next());
        new_node->set_previous(current);
        current->get_next()->set_previous(new_node);
        current->set_next(new_node);

        // Update the indices of following nodes
        int new_index = index_to_insert;
        while (new_node != nullptr) {
            new_node->set_index(new_index);
            new_node = new_node->get_next();
            new_index++;
        }

        this->size++;
    }
}


void ArbitraryList::update_value_at_index(int index, int value){
    if (index <= this->size) {
        Node *current = this->head;

        while (current->get_index() != index) {
            current = current->get_next();
        }

        current->set_value(value);
        // std::cout << "updated value at index " << index << " to " << value << std::endl;
    }
};

int ArbitraryList::get_value_at_index(int index){
    if (index >= 0 && index < this->size) {
        Node *current = this->head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex != index) {
            current = current->get_next(); // walk through the list of nodes
            currentIndex++;
        }

        if (current != nullptr) {
            return current->get_value();
        } else {
            std::cout << "Index out of bounds" << std::endl;
            return -1;
        }
    } else {
        std::cout << "Index out of bounds" << std::endl;
        return -1;
    }
}

int ArbitraryList::get_size(){
    return this->size;
};

Node* ArbitraryList::get_head(){
    return this->head;
}

Node* ArbitraryList::get_tail(){
    return this->tail;
}

void ArbitraryList::print(){
    Node* current = this->head;
    std::cout << current->get_value() << std::endl;
    while (current->get_next() != nullptr) {
        current = current->get_next(); // walk through the list of nodes
        std::cout << current->get_value() << std::endl;
    }
}