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
    // string hash function
    std::hash<string> string_hash;
    
    // hash value
    size_t hashed_key = string_hash(key);

    // convert hash value to int and ensure it's positive
    int index = static_cast<int>(hashed_key) % capacity;
    index = (index < 0) ? -index : index; // take absolute value
    
    return index;
}


int HashTable::add(string key, string value){
    int index = hash(key);

    bool collision = (array[index] != value && array[index] != "");

    if (collision) {
        collision_count += 1;
        cout << "Collision at index: " << index << endl;
        array[index] = value;
    } else {
        size++;
        array[index] = value;
        // resize when smarter, also handle collisions
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

int HashTable::get_collisions() {
    return collision_count;
}

bool HashTable::contains(string value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}