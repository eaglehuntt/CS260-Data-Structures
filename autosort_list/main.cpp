#include <iostream>
#include <string>
#include <limits>

#include "autosort_list.cpp" // Include header file for AutosortList
#include "../node.cpp"

using namespace std;

bool test_autosort() {
    cout << "Testing autosort..." << endl;
    AutosortList *list = new AutosortList();

    // Test autosort
    list->push(3);
    list->push(1);
    list->push(2);

    if (list->get_size() != 3 || list->get_value_at_index(0) != 1 ||
        list->get_value_at_index(1) != 2 || list->get_value_at_index(2) != 3) {
        delete list;
        return false;
    }

    delete list;
    return true;
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
    if (test_autosort()) {
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
