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

    if (this->size == 0){
        this->head = new_node;
        this->tail = new_node;
        this->size++;
    } else {
        Node *old_tail = this->tail;
        new_node->set_index(this->size); // the index of the new node will be the size of the list
        this->tail->set_next(new_node);
        this->tail = new_node;
        this->tail->set_previous(old_tail);
        this->size++;
    }
};

void ArbitraryList::pop(){
    if (this->size < 0){
        
    }
};

// will be useful later when I need to walk through the list of nodes
//  Node *current = this->head();

//         // walk through the list of nodes
//         while (current->get_next() != nullptr){
//             current = current->get_next();
//         }

//         current->set_next(new_node);

void ArbitraryList::remove(int index){

};

void ArbitraryList::insert(int index, int value){

};

void ArbitraryList::update(int index, int value){

};

void ArbitraryList::peek(int index){

};

int ArbitraryList::get_size(){
    return this->size;
};

Node* ArbitraryList::get_head(){
    return this->head;
}

Node* ArbitraryList::get_tail(){
    return this->tail;
}