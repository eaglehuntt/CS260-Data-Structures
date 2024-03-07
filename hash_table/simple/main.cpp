#include "hash_table.cpp"
#include <string>

using std::string;

int main(){

    HashTable *ht = new HashTable;

    string x = "hello";
    string y = "world";

    std::cout << "Hashed key for 'hello': " << ht->hash(x) << std::endl;
    std::cout << "Hashed key for 'world': " << ht->hash(y) << std::endl;


    // ht->add(x, y);
    // string z = ht->get_value(x);

    // cout << z << endl;
    return 1;
}