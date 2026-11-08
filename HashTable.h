#pragma once
#include <string>
#include <vector>
#include <cctype>

template <typename T>
class HashTable {
public:
    HashTable() {
        table.resize(1000); // arbitrary starting size, will resize as needed
        count = 0;
    }

    void insert(const std::string& key, T* value) {
        // WIP
    }

    std::vector<T*> search(const std::string& prefix, int limit) const {
        // WIP
    }
    
    std::vector<T*> search(const std::string& prefix) const {
        // WIP
    }

private:
    struct Node {
        std::string prefix;
        std::vector<T*> results; // these are the matching results
    };

    std::vector<std::vector<Node>> table; // the actual hash table
    size_t count;

    // using djb2 hash function concepts
    int hashString(std::string str) const {
        size_t hash = 5381;

        for (int i = 0; i < str.size(); i++) {
            hash = hash * 33 + (unsigned char)str[i];
        }

        return hash % table.size();
    }

    static std::string toLower(std::string str) {
        for (int i = 0; i < str.size(); i++) {
            str[i] = std::tolower((unsigned char)str[i]); // unsigned char prevents negative values
        }

        return str;
    }

    void resize() {
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
};