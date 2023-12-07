/*Copyright© 2023 Rohan Chakaravarty
This header file contains Hash Table Functionality:
    -> Mid Square & Division Method
    -> Linear & Quadratic Probing
    -> Separate Chaining
    -> Double Hashing
    

This is opensource project and feel free contribute*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>

// Hash_Table class
class Hash_Table {
private:
    int size; // Size of the hash table
    std::vector<std::list<int>> table; // Vector of linked lists for separate chaining

    // Hash function using Mid Square Method
    int midSquareHash(int key) {
        int squared = key * key;
        std::string str = std::to_string(squared);
        int len = str.length();

        // Extracting middle digits for the hash value
        int start = (len / 2) - 1;
        int end = start + 2;
        std::string midDigits = str.substr(start, end);
        return std::stoi(midDigits);
    }

    // Hash function using Division Method
    int divisionHash(int key) {
        return key % size;
    }

    // Resolve hash collisions using linear probing
    int linearProbing(int index, int i) {
        return (index + i) % size;
    }

    // Resolve hash collisions using quadratic probing
    int quadraticProbing(int index, int i) {
        return (index + i * i) % size;
    }

    // Resolve hash collisions using double hashing
    int doubleHashing(int key, int i) {
        int hash1 = divisionHash(key);
        int hash2 = midSquareHash(key);
        return (hash1 + i * hash2) % size;
    }

public:
    // Constructor
    Hash_Table(int tableSize) : size(tableSize), table(tableSize) {}

    // Function to insert key into the hash table
    void insert(int key) {
        int index = divisionHash(key); // You can choose hash function here

        // Example: Using linear probing
        int i = 0;
        while (!table[index].empty()) {
            // Resolve collision with linear probing
            // index = linearProbing(index, i);

            // Resolve collision with quadratic probing
            // index = quadraticProbing(index, i);

            // Resolve collision with double hashing
            index = doubleHashing(key, i);

            i++;
        }

        table[index].push_back(key);
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << i << " --> ";
            for (int val : table[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

// // Example usage
// int main() {
//     Hash_Table hashTable(10); // Hash table of size 10

//     // Inserting elements
//     hashTable.insert(12);
//     hashTable.insert(22);
//     hashTable.insert(42);
//     hashTable.insert(32);
//     hashTable.insert(52);
//     hashTable.insert(8);
//     hashTable.insert(92);
//     hashTable.insert(10);

//     // Displaying the hash table
//     hashTable.display();

//     return 0;
// }


#endif