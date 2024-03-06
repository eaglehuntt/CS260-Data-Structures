#include <string>
#include <vector>

using std::string;
using std::vector;


class HashTable {
public:
    HashTable();
    int hash(string key);
    int add(string key, string value);
    bool remove(string key);
    bool get_value(string key);

    string to_string();
    int get_size();
    int get_collisions(); 

private:
    int capacity = 10;
    int size = 0;
    int collision_count = 0; // Added collision count variable

    string *storage = nullptr;
    bool resize();
};