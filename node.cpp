#include <stdexcept> 

#include "node.hpp"

// private 

void Node::set_value(int new_value){
    this->value = new_value;    
};

// redundant for now, but will be useful later if I want to add logic to determine a valid value
bool Node::is_valid_value(int value){
    if (value == value){
        return true;
    }
    else{
        return false;
    }
};

// public

Node::Node(){
    this->index = 0;
    this->value = 0;
    this->next = nullptr;
};

Node::Node(int new_value){
    this->value = new_value;
}

void Node::set_id(int new_id){
    this->index = new_id;
};

void Node::new_value(int new_value){
    if (this->is_valid_value(new_value)){
        this->set_value(new_value);
    } else {
        throw std::invalid_argument("Invalid value");
    }
};

void Node::set_next(Node* new_next){
    this->next = new_next;
};

void Node::set_previous(Node* new_prev){
    this->previous = new_prev;
};

int Node::get_value(){
    return this->value;
}

Node* Node::get_next(){
    return this->next;
};

Node* Node::get_previous(){
    return this->previous;
};

// Wrapper methods for next and previous, for a better interface when working with trees
void Node::set_right(Node* new_right){
    this->set_next(new_right);
};

void Node::set_left(Node* new_left){
    this->set_previous(new_left);
};