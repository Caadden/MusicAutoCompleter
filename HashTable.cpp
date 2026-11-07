#include "HashTable.h"

HashTable::HashTable() {
    table.resize(1000); // arbitrary starting size, will resize as needed
    count = 0;
}

std::string HashTable::toLower(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = std::tolower((unsigned char)str[i]); // unsigned char prevents negative values
    }
    
    return str;
}

// using djb2 hash function concepts
int HashTable::hashString(std::string str) const {
    size_t hash = 5381;

    for (int i = 0; i < str.size(); i++) {
        hash = hash * 33 + (unsigned char)str[i];
    }

    return hash % table.size();
}

void HashTable::resize() {
    std::vector<std::vector<Node>> oldTable = table;

    table.clear();
    table.resize(oldTable.size() * 2);

    for (int i = 0; i < oldTable.size(); i++) {
        for (int j = 0; j < oldTable[i].size(); j++) {
            int newIdx = hashString(oldTable[i][j].prefix);
            table[newIdx].push_back(oldTable[i][j]);
        }
    }
}