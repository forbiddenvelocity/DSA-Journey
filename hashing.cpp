#include <iostream>
#include <list>
using namespace std;

class HashTableSeparateChaining {
private:
    static const int tableSize = 10; // Size of the hash table
    list<int> table[tableSize]; // Array of linked lists

    // Hash function
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Insert an element into the hash table using separate chaining
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for an element in the hash table using separate chaining
    bool search(int key) {
        int index = hashFunction(key);
        list<int>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key)
                return true;
        }
        return false;
    }

    // Remove an element from the hash table using separate chaining
    void remove(int key) {
        int index = hashFunction(key);
        list<int>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Display the hash table using separate chaining
    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            list<int>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

class HashTableOpenAddressing {
private:
    static const int tableSize = 10; // Size of the hash table
    int table[tableSize]; // Array to store the elements

public:
    HashTableOpenAddressing() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = -1; // Initialize all elements as -1 (indicating empty slot)
        }
    }

    // Hash function for open addressing
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Insert an element into the hash table using open addressing
    void insert(int key) {
        int index = hashFunction(key);

        // Find next available slot using linear probing
        while (table[index] != -1) {
            index = (index + 1) % tableSize;
        }

        table[index] = key;
    }

    // Search for an element in the hash table using open addressing
    bool search(int key) {
        int index = hashFunction(key);

        // Find the element using linear probing
        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % tableSize;
        }

        return false;
    }

    // Remove an element from the hash table using open addressing
    void remove(int key) {
        int index = hashFunction(key);

        // Find the element using linear probing
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                break;
            }
            index = (index + 1) % tableSize;
        }
    }

    // Display the hash table using open addressing
    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    // Hashing with Separate Chaining
    HashTableSeparateChaining hashTableSC;

    hashTableSC.insert(5);
    hashTableSC.insert(15);
    hashTableSC.insert(25);
    hashTableSC.insert(6);
    hashTableSC.insert(16);
    hashTableSC.insert(26);
    hashTableSC.insert(7);
    hashTableSC.insert(17);
    hashTableSC.insert(27);

    cout << "Separate Chaining Hash Table:" << endl;
    hashTableSC.display();

    cout << "Search 15: " << (hashTableSC.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (hashTableSC.search(10) ? "Found" : "Not Found") << endl;

    hashTableSC.remove(15);

    cout << "Hash Table after removing 15:" << endl;
    hashTableSC.display();

    cout << endl;

    // Hashing with Open Addressing
    HashTableOpenAddressing hashTableOA;

    hashTableOA.insert(5);
    hashTableOA.insert(15);
    hashTableOA.insert(25);
    hashTableOA.insert(6);
    hashTableOA.insert(16);
    hashTableOA.insert(26);
    hashTableOA.insert(7);
    hashTableOA.insert(17);
    hashTableOA.insert(27);

    cout << "Open Addressing Hash Table:" << endl;
    hashTableOA.display();

    cout << "Search 15: " << (hashTableOA.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (hashTableOA.search(10) ? "Found" : "Not Found") << endl;

    hashTableOA.remove(15);

    cout << "Hash Table after removing 15:" << endl;
    hashTableOA.display();

    return 0;
}
