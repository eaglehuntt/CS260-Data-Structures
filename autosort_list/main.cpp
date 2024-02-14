#include <iostream>
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
    cout << "[   p   ] push <int> - Push a node with the given value to the list" << endl;
    cout << "[   o   ] pop - Pop a node from the list" << endl;
    cout << "[   g   ] get <index> - Get the value of the node at the given index" << endl;
    cout << "[   s   ] size - Get the size of the list" << endl;
    cout << "[ print ] - Print the list" << endl;
    cout << "[   h   ] help - Print this help message" << endl;
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

        if(command == "p" || command == "P") {
            int value;
            cin >> value;
            list->push(value);
        } else if(command == "o" || command == "O") {
            list->pop();
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
