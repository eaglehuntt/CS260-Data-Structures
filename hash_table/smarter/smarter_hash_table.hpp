#include <string>
using std::string;


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
    int capacity;
    int size;
    int collision_count;

    string *array = nullptr;
    bool resize();
};