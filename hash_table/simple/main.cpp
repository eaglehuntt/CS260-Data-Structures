#include "hash_table.cpp"
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

bool test_contains(){ // this also tests adding
    bool passed;
    HashTable *ht = new HashTable;

    ht->add("hello", "world");
    bool contains_hello = ht->contains("hello");
    bool contains_world = ht->contains("world");

    if (!contains_hello && contains_world){
        passed = true;
        cout << "test_contains: Passed" << endl;
    } else { 
        passed = false;
        cout << "test_contains: Failed" << endl;
    }

    delete ht;
    return passed;
}

bool test_get_value() {
    bool passed;
    HashTable *ht = new HashTable;

    ht->add("hello", "world");

    string z = ht->get_value("test"); 
    string y = ht->get_value("hello");

    if (z == "" && y == "world"){
        cout << "test_get_value: Passed" << endl;
        passed = true;
    } else {
        cout << "test_get_value: Failed" << endl;
        passed = false;
    }

    delete ht;
    return passed;
}

bool test_get_collisions(){
    bool passed;
    HashTable *ht = new HashTable;

    // through a lot of frustration I found out the hard way these collide
    ht->add("hello", "world");
    ht->add("world", "hello");

    if (ht->get_collisions() == 1){
        passed = true;
        cout << "test_collisions: Passed" << endl;
    } else { 
        passed = false;
        cout << "test_collisions: Failed" << endl;
    }

    delete ht;
    return passed;
}

bool run_tests(){
    bool result = (test_contains() && test_get_value() && test_get_collisions());
    return result;
}

void displayMenu() {
    cout << "1. Add key-value pair" << endl;
    cout << "2. Get value for key" << endl;
    cout << "3. Check if value exists" << endl;
    cout << "4. Display number of collisions" << endl;
    cout << "5. Exit" << endl;
}

// cli made with chatgpt
int main() {
    run_tests();
    HashTable ht;
    int choice;
    string key, value;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                ht.add(key, value);
                cout << "Key-value pair added successfully." << endl;
                cout << endl;
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                cout << endl;
                cout << "Value for key '" << key << "': " << ht.get_value(key) << endl;
                cout << endl;
                break;
            case 3:
                cout << "Enter value to check: ";
                cin >> value;
                if (ht.contains(value)) {
                    cout << "Value '" << value << "' exists in the hash table." << endl;
                    cout << endl;
                } else {
                    cout << "Value '" << value << "' does not exist in the hash table." << endl;
                    cout << endl;
                }
                break;
            case 4:
                cout << "Number of collisions: " << ht.get_collisions() << endl;
                cout << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                cout << endl;
        }

    } while (choice != 5);

    return 0;
}