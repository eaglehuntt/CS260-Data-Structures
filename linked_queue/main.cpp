#include <iostream>

#include "linked_queue.cpp" // bad practice
#include "../node.cpp"

using namespace std;

bool test () {
    LinkedQueue *testQueue = new LinkedQueue();
    
    testQueue->enqueue(1);
    
    if (testQueue->peek_head() != 1) {
        return false;
    }

    testQueue->enqueue(2);
    testQueue->enqueue(3);
    testQueue->enqueue(4);

    testQueue->dequeue();

    if (testQueue->peek_head() != 2) {
        return false;
    }

    return true;
}


// CLI Generated with AmazonQ.
// Prompt: write me a CLI for my linkedqueue data structure

void printHelp() {
  cout << "Linked Queue CLI" << endl;
  cout << "Commands:" << endl;
  cout << "[ e ] enqueue <int> - Add a node with given value to the queue" << endl; 
  cout << "[ d ] dequeue - Remove node from head of queue and print its value" << endl;
  cout << "[ p ] peek - Print value of node at head of queue" << endl;
  cout << "[ h ] help - Print this help message" << endl;
}


int main(){
    
    cout << "Running tests..." << endl;
    if (test()){
        cout << "Tests passed. Running demo..." << endl;
    } else {
        cout << "Tests failed!" << endl;
        return -1;
    }


    LinkedQueue q;

    printHelp();

    while(true) {

        string command;
        cout << "> ";
        cin >> command;

        if(command == "e" || command == "E") {
        int value;
        cin >> value;
        q.enqueue(value);
        }

        else if(command == "d" || command == "D") {
        q.dequeue(); 
        }

        else if(command == "p" || command == "P") {
        cout << q.peek_head() << endl;
        }

        else if(command == "h" || command == "H") {
        printHelp();
        }

        else {
        cout << "Invalid command" << endl;
        }

    }

    return 0;
}