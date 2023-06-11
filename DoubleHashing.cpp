#include <iostream>

class HashTable {
private:
    int tableSize;
    int* hashTable;
    bool* isOccupied;

public:
    HashTable(int size) {
        tableSize = size;
        hashTable = new int[tableSize];
        isOccupied = new bool[tableSize];
        for (int i = 0; i < tableSize; i++) {
            hashTable[i] = -1;  // Initialize the hash table with -1 (indicating empty)
            isOccupied[i] = false;  // Initialize the isOccupied array with false
        }
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    int secondHashFunction(int key) {
        // Choose a prime number smaller than the table size
        int prime = 7;
        return prime - (key % prime);
    }

    void insert(int key) {
        int hashValue = hashFunction(key);
        int stepSize = secondHashFunction(key);

        while (isOccupied[hashValue]) {
            hashValue = (hashValue + stepSize) % tableSize;
        }

        hashTable[hashValue] = key;
        isOccupied[hashValue] = true;
    }

    bool search(int key) {
        int hashValue = hashFunction(key);
        int stepSize = secondHashFunction(key);

        while (isOccupied[hashValue]) {
            if (hashTable[hashValue] == key) {
                return true;  // Key found
            }
            hashValue = (hashValue + stepSize) % tableSize;
        }

        return false;  // Key not found
    }

    void remove(int key) {
        int hashValue = hashFunction(key);
        int stepSize = secondHashFunction(key);

        while (isOccupied[hashValue]) {
            if (hashTable[hashValue] == key) {
                hashTable[hashValue] = -1;  // Mark the slot as empty
                isOccupied[hashValue] = false;
                return;
            }
            hashValue = (hashValue + stepSize) % tableSize;
        }
    }

    ~HashTable() {
        delete[] hashTable;
        delete[] isOccupied;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    std::cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 20: " << (ht.search(20) ? "Found" : "Not Found") << std::endl;

    ht.remove(25);
    std::cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << std::endl;

    return 0;
}
