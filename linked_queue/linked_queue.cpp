#include <iostream>

#include "./linked_queue.hpp"

// public

LinkedQueue::LinkedQueue() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedQueue::enqueue(int value) {
    Node *newNode = new Node(value);
    newNode->set_id(this->size);

    this->tail = newNode;
    newNode->set_next(this->head);
    

    if (this->size == 0) {
        this->head = newNode;        
    } 

    this->size++;

    std::cout << "Enqueued " << value << std::endl;        

    return;
}

void LinkedQueue::dequeue() {
    std::cout << "Attempting to dequeue"<< std::endl;
    if (this->head != nullptr) {
        Node *temp = this->head;
        this->head = this->head->get_next();
        this->size--;
        delete temp;
    }

}

int LinkedQueue::peek_head() {
    if (this->head != nullptr) {
        return this->head->get_value();
    }
    else {
        throw "Queue is empty";
    }
}
