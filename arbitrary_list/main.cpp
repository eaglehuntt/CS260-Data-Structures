#include <iostream>

#include "arbitrary_list.cpp" // bad practice
#include "../node.cpp"

using namespace std;

/* 
    I made this CLI by modifying code generated with ChatGPT

    Prompt: 
    
    Here is a previous CLI I made for a Queue:
    [ linked_queue/main.cpp's code ]

    Write me a CLI for my Arbitrary List

    [ arbitrary_list.hpp's code ]

    Also, like the CLI I provided, write me tests for each method.
    

    ---
    Doing this actually helped me find a few bugs in my code, so I thought it was helpful.
*/


bool test_push_pop() {
    cout << "Testing push and pop..." << endl;
    ArbitraryList *list = new ArbitraryList(); // Initialize the pointer
    
    // Test push
    list->push(1);
    list->push(2);
    list->push(3);

    // Test pop
    list->pop();
    if (list->get_size() != 2 || list->get_value_at_index(1) != 2) {
        delete list; 
        return false;
    }

    delete list;
    return true;
}

bool test_remove_at_index() {
    cout << "Testing remove_at_index..." << endl;
    ArbitraryList *list = new ArbitraryList(); 
    
    // Test remove_at_index
    list->push(1);
    list->push(2);
    list->push(3);
    list->remove_at_index(1);
    if (list->get_size() != 2 || list->get_value_at_index(1) != 3) {
        delete list; 
        return false;
    }

    return true;
}

bool test_insert_at_index() {
    cout << "Testing insert_at_index..." << endl;
    ArbitraryList *list = new ArbitraryList(); 
    
    // Test insert_at_index
    list->push(1);
    list->push(3);
    list->insert_at_index(1, 2);

    if (list->get_size() != 3 || list->get_value_at_index(1) != 2) {
        delete list; 
        return false;
    }
    delete list; 
    return true;
}

bool test_update_value_at_index() {
    cout << "Testing update_value_at_index..." << endl;
    ArbitraryList *list = new ArbitraryList(); 
    
    // Test update_value_at_index
    list->push(1);
    list->push(2);
    list->push(3);
    list->update_value_at_index(1, 4);
    if (list->get_size() != 3 || list->get_value_at_index(1) != 4) {
        delete list; 
        return false;
    }
    delete list; 
    return true;
}

bool test_get_value_at_index() {
    cout << "Testing get_value_at_index..." << endl;
    ArbitraryList *list = new ArbitraryList(); 
    
    // Test get_value_at_index
    list->push(1);
    list->push(2);
    list->push(3);

    if (list->get_value_at_index(1) != 2) {
        delete list; 
        return false;
    }
    delete list; 
    return true;
}

void printHelp() {
    cout << "Arbitrary List CLI" << endl;
    cout << "Commands:" << endl;
    cout << "[   p   ] push <int> - Push a node with given value to the list" << endl;
    cout << "[   o   ] pop - Pop a node from the list" << endl;
    cout << "[   r   ] remove <index> - Remove node at the given index" << endl;
    cout << "[   i   ] insert <index> <int> - Insert a node with given value at the given index" << endl;
    cout << "[   u   ] update <index> <int> - Update the value of the node at the given index" << endl;
    cout << "[   g   ] get <index> - Get the value of the node at the given index" << endl;
    cout << "[   s   ] size - Get the size of the list" << endl;
    cout << "[ print ] - Print the list" << endl;
    cout << "[   h   ] help - Print this help message" << endl;
}

int main() {
    cout << "Running tests..." << endl;
    if (test_push_pop() && test_remove_at_index() && test_insert_at_index() && test_update_value_at_index() && test_get_value_at_index()) {
        cout << "All tests passed. Running demo..." << endl;
        cout << endl;
    } else {
        cout << "Tests failed!" << endl;
        return -1;
    }

    ArbitraryList *list = new ArbitraryList;
    printHelp();

    while(true) {
        string command;
        cout << "> ";
        cin >> command;

        if(command == "p" || command == "P") {
            int value;
            cin >> value;
            list->push(value);
        } else if(command == "o" || command == "O") {
            list->pop();
        } else if(command == "r" || command == "R") {
            int index;
            cin >> index;
            list->remove_at_index(index);
        } else if(command == "i" || command == "I") {
            int index, value;
            cin >> index >> value;
            list->insert_at_index(index, value);
        } else if(command == "u" || command == "U") {
            int index, value;
            cin >> index >> value;
            list->update_value_at_index(index, value);
        } else if(command == "g" || command == "G") {
            int index;
            cin >> index;
            cout << "Value at index " << index << ": " << list->get_value_at_index(index) << endl;
        } else if(command == "s" || command == "S") {
            cout << "Size: " << list->get_size() << endl;
        } else if(command == "print" || command == "PRINT") {
            list->print();
        } else if(command == "h" || command == "H" || command == "help") {
            printHelp();
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
