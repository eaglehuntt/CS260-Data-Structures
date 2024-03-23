Hash Table Structure:
Array: An interal array will be used to store the values in the hash table.
Hash Function: A hash function will be used to convert a string (key) to an index within the array
Collision Handling: A dumb hash table will just over write the values, but a smarter one will handle the collision

Hash tables are very useful when you want a O(1) look up time. Because a user will know the key to access it, as long as the hash function is good we can get the exact point in memory their data is at.

They can be used in cryptography, complex data structures, or be useful in a coding interview.

When comparing my dumb vs smarter hashtable, there seem to be way fewer collisions, and when there is a collision the smarter one handles it a lot better.

On the dumb hashtable, the write time and lookup time are always O(1), but it will just overwrite a previous value if there is a collision.

The smarter hashtable handles collisions with a secondary hashing method, but its write method could be O(n) worst case.
