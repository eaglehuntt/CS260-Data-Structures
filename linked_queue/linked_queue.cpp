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

    if (this->size == 0) {
        this->head = newNode;        
    } else {
        this->tail->set_next(newNode);
    }

    this->tail = newNode;
    newNode->set_next(nullptr);

    this->size++;

    std::cout << "Enqueued " << value << std::endl;        

    return;
}

void LinkedQueue::dequeue() {
    if (this->head != nullptr) {
        Node *temp = this->head;
        
        if (this->size != 1) {
            this->head = this->head->get_next();
        } else {
            this->head = nullptr;
        }
        this->size--;
        delete temp;
    } else {
        std::cout << "Attemped to dequeue. Queue is empty." << std::endl;
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

int LinkedQueue::get_size() {
    return this->size;
}
