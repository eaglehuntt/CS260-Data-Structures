#include <iostream>

#include "linked_queue.cpp" // bad practice
#include "../node.cpp"


int main(){
    LinkedQueue *myQueue = new LinkedQueue();
    myQueue->enqueue(1);
    myQueue->enqueue(2);
    myQueue->enqueue(3);

    std::cout << myQueue->peek_head() << std::endl;

    myQueue->dequeue();
    
    std::cout << myQueue->peek_head() << std::endl;

    return 0;
}