#include "hash_table.hpp"
#include <iostream>

using std::cout;
using std::endl;

HashTable::HashTable() {
    array.resize(capacity);
}

int HashTable::hash(string key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c); 
    }
    return sum % capacity; 
}

// O(n) worst case if there is a collision
int HashTable::double_hash(string key) {
    // for double hashing, capacity should be a prime number
    // source: https://www.cs.utexas.edu/~mitra/csSpring2017/cs313/lectures/hash.html#:~:text=Double%20hashing%20requires%20that%20the,will%20eventually%20check%20every%20cell.

    int hashed = hash(key);
    // Ensure result remains non-negative
    if (hashed < 0)
        hashed += capacity;
    // Call get_next_prime on the result
    return get_next_prime(hashed);
}

int HashTable::add(string key, string value) {
    int index = hash(key); 
    
    if (size >= capacity / 2) { 
        resize();
    }

    // Check for collision at the index
    if (array[index] != "") {
        // Collision occurred, use double hashing to find next available slot
        int step = double_hash(key);
        while (array[index] != "") {
            index = (index + step) % capacity;
        }
    }

    // Insert the value at the computed index
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
    capacity = get_next_prime(capacity * 2);
    
    // Create new vector with new capacity
    vector<string> new_array(capacity);

    // Rehash and transfer items to new array
    for (int i = 0; i < old_capacity; ++i) {
        if (array[i] != "") {
            int index = double_hash(array[i]);
            // Ensure index is within bounds of new array
            if (index >= 0 && index < capacity) {
                new_array[index] = array[i];
            } else {
                cout << "Index out of bounds during resize: " << index << endl;
            }
        }
    }

    // Move ownership to new array
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