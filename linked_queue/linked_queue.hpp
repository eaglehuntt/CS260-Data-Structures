
#include "../node.hpp"

class LinkedQueue {
    private:
        int size;
        Node *head;
        Node *tail;

    public:
        LinkedQueue();
        void enqueue(int value);
        void dequeue();
        int peek_head();
    };