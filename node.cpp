#include <stdexcept> 

#include "node.hpp"

// private 

void Node::set_id(int new_id){
    this->id = new_id;
};


void Node::set_value(int new_value){
    this->value = new_value;    
};


// redundant for now, but will be useful later if I want to add logic to what is a valid value
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
    this->id = 0;
    this->value = 0;
    this->next = nullptr;
};

Node::Node(int new_id, int new_value){
    this->id = new_id;
    this->value = new_value;
}

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