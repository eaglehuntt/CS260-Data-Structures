#include "hash_table.cpp"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

bool test_double_hash() {
    HashTable ht;
    string key = "test";
    int hashed_value = ht.double_hash(key);
    // Check if the hashed value is within the range of the hash table capacity
    bool result = (hashed_value >= 0 && hashed_value < ht.get_capacity());
    cout << "test_double_hash: ";
    if (result)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
    return result;
}


bool test_hash() {
    HashTable ht;
    string key = "test";
    int hashed_value = ht.hash(key);
    // Check if the hashed value is within the range of the hash table capacity
    bool result = (hashed_value >= 0 && hashed_value < ht.get_capacity());
    cout << "test_hash: ";
    if (result)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
    return result;
}

bool test_get_next_prime() {
    HashTable ht;
    int prime = ht.get_next_prime(10);
    // Test if it correctly finds the next prime number
    bool result = (prime > 10); // Prime number should be greater than 10
    cout << "test_get_next_prime: ";
    if (result)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
    return result;
}

bool test_is_prime() {
    HashTable ht;
    bool prime = ht.is_prime(11);
    // Test if it correctly identifies prime numbers
    bool result = prime;
    cout << "test_is_prime: ";
    if (result)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
    return result;
}

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

    string y = ht->get_value("hello");

    if (y == "world"){
        cout << "test_get_value: Passed" << endl;
        passed = true;
    } else {
        cout << "test_get_value: Failed" << endl;
        passed = false;
    }

    delete ht;
    return passed;
}

bool test_collisions(){
    bool passed;
    HashTable *ht = new HashTable;

    // This collided on the dumb one, but not anymore!
    ht->add("hello", "world");
    ht->add("world", "hello");

    if (ht->get_collisions() != 1){
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
    cout << "Running tests..." << endl;
    return (test_hash() && test_double_hash() && test_contains() && test_get_value() && test_collisions() && test_get_next_prime() && test_is_prime());
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
    if (run_tests()){
        HashTable ht;
            int choice;
            string key, value;

            do {
                cout << endl;
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
    } else {
        return 1;
    }
    
}