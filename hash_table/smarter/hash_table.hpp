#include <iostream>
#include <functional>
#include <vector>
#include <string>

using std::string;
using std::vector;

class HashTable {
public:
    HashTable();
    int hash(string key);
    int double_hash(string key);
    int add(string key, string value);
    string get_value(string key);
    int get_collisions();
    bool contains(string value);
    int get_next_prime(int n);
    bool is_prime(int n);
    int get_capacity();

private:
    int capacity = 7;
    int size = 0;
    int collision_count = 0;
    vector<string> array;

    void resize();
};