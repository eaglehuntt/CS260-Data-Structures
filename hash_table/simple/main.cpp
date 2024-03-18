#include "hash_table.cpp"
#include <string>

using std::string;

int main() {
    HashTable *ht = new HashTable;

    // Add key-value pairs that may result in collisions
    ht->add("hello", "world");
    ht->add("cat", "meow");
    ht->add("banana", "fruit");
    ht->add("apple", "fruit");
    ht->add("table", "furniture");
    ht->add("chair", "furniture");
    ht->add("sofa", "furniture");
    ht->add("lamp", "furniture");
    ht->add("pen", "writing instrument");
    ht->add("pencil", "writing instrument");
    ht->add("marker", "writing instrument");
    ht->add("book", "reading material");
    ht->add("newspaper", "reading material");
    ht->add("magazine", "reading material");
    ht->add("desk", "furniture");
    ht->add("bed", "furniture");
    ht->add("wardrobe", "furniture");
    ht->add("orange", "fruit");
    ht->add("shirt", "clothing");
    ht->add("pants", "clothing");
    ht->add("shoes", "footwear");
    ht->add("socks", "footwear");
    ht->add("gloves", "clothing");
    ht->add("hat", "clothing");
    ht->add("scarf", "clothing");
    ht->add("glasses", "eyewear");
    ht->add("watch", "accessory");
    ht->add("bracelet", "accessory");
    ht->add("necklace", "accessory");
    ht->add("ring", "accessory");
    ht->add("earrings", "accessory");
    ht->add("bag", "accessory");
    ht->add("backpack", "accessory");
    ht->add("wallet", "accessory");
    ht->add("phone", "electronic device");
    ht->add("tablet", "electronic device");
    ht->add("laptop", "electronic device");
    ht->add("keyboard", "computer peripheral");
    ht->add("mouse", "computer peripheral");
    ht->add("headphones", "audio accessory");
    ht->add("earbuds", "audio accessory");
    ht->add("speaker", "audio accessory");
    ht->add("microphone", "audio accessory");
    ht->add("monitor", "computer peripheral");
    ht->add("dog", "bark");

    // Retrieve values for some keys
    string output_hello = ht->get_value("hello");
    string output_cat = ht->get_value("cat");
    string output_orange = ht->get_value("orange");

    // Output the retrieved values
    cout << "Value for 'hello': " << output_hello << endl;
    cout << "Value for 'cat': " << output_cat << endl;
    cout << "Value for 'orange': " << output_orange << endl;
    cout << ht->get_collisions() << endl;
    cout << "ht->contains('Nan'): " << ht->contains("NaN") << endl;
    cout << "ht->contains('bark'): " << ht->contains("bark") << endl;


    // Clean up memory
    delete ht;
    return 0;
}