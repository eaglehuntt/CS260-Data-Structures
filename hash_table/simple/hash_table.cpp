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
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c); 
    }
    return sum % capacity; 
}

int HashTable::add(string key, string value) {
    int index = hash(key);

    if (array[index] != "") {
        collision_count++;
    } else {
        size++;
    }

    array[index] = value;
    return index;
}


string HashTable::get_value(string key) {
    string result = "";
    int index = hash(key);
    if (array[index] != "") {
        result = array[index];
    } 
    return result;
}

int HashTable::get_collisions() {
    return collision_count;
}

bool HashTable::contains(string value) {
    for (int i = 0; i < capacity; ++i) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}