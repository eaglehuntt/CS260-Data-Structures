#include "hash_table.hpp"
#include <iostream>

using std::cout;
using std::endl;

HashTable::HashTable() {
    array.resize(capacity);
}

int HashTable::hash(string key) {
    std::hash<string> hasher;
    return hasher(key) % capacity;
}

// O(n) worst case if there is a collision
int HashTable::double_hash(string key) {
    // for double hashing, capacity should be a prime number
    // source: https://www.cs.utexas.edu/~mitra/csSpring2017/cs313/lectures/hash.html#:~:text=Double%20hashing%20requires%20that%20the,will%20eventually%20check%20every%20cell.

    int index = hash(key);

    // add 1 to second hash to ensure it is not 0
    int second_hash = 1 + (std::hash<string>{}(key) % (capacity - 1)); // Secondary hash function
    
    // keeps iterating over the array until an open spot is found. collisions are only counted when a new collision occurs, not for each probe attempt.
    int offset = 1;
    while (array[index] != "") {
        index = (index + offset * second_hash) % capacity;
        offset++;
        if (array[index] != "")
            collision_count++;
    }
    return index;
}

int HashTable::add(string key, string value) {
    // the sooner we resize the less collisions we get
    if (size >= capacity / 2) { 
        resize();
    }
    int index = double_hash(key);
    array[index] = value;
    size++;
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
    for (const auto& item : array) {
        if (item == value)
            return true;
    }
    return false;
}

int HashTable::get_next_prime(int n) {
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

void HashTable::resize() {
    int old_capacity = capacity;
    // get the next closest prime number to capacity * 2
    capacity = get_next_prime(capacity * 2);
    
    // make a new vector with the new capacity
    vector<string> new_array(capacity);

    // Rehash the items and put them into the new array
    for (int i = 0; i < old_capacity; ++i) {
        if (array[i] != "") {
            int index = double_hash(array[i]);
            new_array[index] = array[i];
        }
    }

    // transfer ownership from old array to new array
    array = std::move(new_array);
}

bool HashTable::is_prime(int n) {
    // method from
    // https://www.geeksforgeeks.org/c-program-to-check-prime-number/
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int HashTable::get_capacity() {
    return capacity;
}