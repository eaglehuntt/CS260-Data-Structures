#include <iostream>
#include <string>
#include <limits>

#include "autosort_list.cpp"
#include "../node.cpp"

using namespace std;

bool test_push() {
    AutosortList *list = new AutosortList;
    list->push(5);
    list->push(2);
    list->push(8);
    list->push(1);
    list->push(4);
    list->push(7);
    
    bool result = list->get_tail()->get_value() == 8;
    delete list;
    return result;
}

bool test_pop() {
    AutosortList *list = new AutosortList;
    list->push(5);
    list->push(2);
    list->push(8);
    list->push(1);
    list->push(4);
    list->push(7);

    list->pop(); 
    list->pop(); 

    bool result = list->get_tail()->get_value() == 5;
    delete list;
    return result;
}

bool test_get_value_at_index() {
    AutosortList *list = new AutosortList;
    list->push(5);
    list->push(2);
    list->push(8);
    list->push(1);
    list->push(4);
    list->push(7);

    bool result = list->get_value_at_index(2) == 4;
    delete list;
    return result;
}

bool test_get_size() {
    AutosortList *list = new AutosortList;
    list->push(5);
    list->push(2);
    list->push(8);
    list->push(1);
    list->push(4);
    list->push(7);

    bool result = list->get_size() == 6;
    delete list;
    return result;
}

bool test_get_head_and_tail() {
    AutosortList *list = new AutosortList;
    list->push(5);
    list->push(2);
    list->push(8);
    list->push(1);
    list->push(4);
    list->push(7);

    int head_value = list->get_head()->get_value(); 
    int tail_value = list->get_tail()->get_value(); 

    bool result = head_value == 1 && tail_value == 8;
    delete list;
    return result;
}

void printHelp() {
    cout << "Autosort List CLI" << endl;
    cout << "Commands:" << endl;
    cout << "[push] <int>   |  Push a node with the given value to the list" << endl;
    cout << "[pop]          |  Pop a node from the list" << endl;
    cout << "[get] <index>  |  Get the value of the node at the given index" << endl;
    cout << "[size]         |  Get the size of the list" << endl;
    cout << "[print]        |  Print the list" << endl;
    cout << "[help]         |  Show this help message" << endl;
}

int main() {
    cout << "Running tests..." << endl;
    if (test_push() && test_pop() && test_get_head_and_tail() && test_get_size() && test_get_head_and_tail()) {
        cout << "All tests passed. Running demo..." << endl;
        cout << endl;
    } else {
        cout << "Tests failed!" << endl;
        return -1;
    }

    AutosortList *list = new AutosortList();
    printHelp();

    while(true) {
        string command;
        cout << "> ";
        cin >> command;

        if(command == "push" || command == "Push") {
            int value;
            cin >> value;
            
            // Check if the input value is an integer
            if (cin.fail()) {
                cout << "Invalid input. Please enter an integer value." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            } else {
                list->push(value);
            }

        } else if(command == "pop" || command == "Pop") {
            list->pop();
        } else if(command == "get" || command == "Get") {
            int index;
            cin >> index;

            if (cin.fail()) {
                cout << "Invalid input. Please enter an integer value for the index." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cout << "Value at index " << index << ": " << list->get_value_at_index(index) << endl;
            }

        } else if(command == "size" || command == "Size") {
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
