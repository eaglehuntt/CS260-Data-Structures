#include "hash_table.hpp"
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::string;

HashTable::HashTable() {
    capacity = 10;
    array = new string[capacity];
}

int HashTable::hash(string key) {
    cout << key << endl;
    // string hash function
    std::hash<string> string_hash;
    
    // hash value, ensure it does not go above capacity
    int hashed_key = string_hash(key) % capacity;

    cout << "hashed key: " << hashed_key << endl;
    
    // if result is negative add the capacity to it
    return (hashed_key < 0) ? hashed_key + capacity : hashed_key;
}

int HashTable::add(string key, string value){
    int index = hash(key);

    bool collision = (array[index] != value && array[index] != "");

    if (collision) {
        collision_count += 1;
        index *= -1; // if index is negative, we collided
    } else {
        size++;
        array[index] = value;
        // resize when smarter
        // if (static_cast<double>(size) / capacity > 0.75) {
        //     resize();
        // }
    }

    return index;
}

string HashTable::get_value(string key) {
    int hashed_key = hash(key);
    bool has_value = (array[hashed_key] != "");
    string value; 

    if (has_value) {
        value = array[hashed_key];
    } else {
        cout << "Value is not in table" << endl;
    }
    return value;    
}