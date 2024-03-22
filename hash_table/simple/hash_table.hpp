#include <string>
using std::string;


class HashTable {
public:
    HashTable();
    int hash(string key);
    int add(string key, string value);
    string get_value(string key);
    int get_size();
    int get_collisions(); 
    bool contains(string value);
    int capacity = 10;

private:
    int size = 0;
    int collision_count = 0;

    string *array = nullptr;
    //bool resize();
};