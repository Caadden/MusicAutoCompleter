#pragma once
#include <string>
#include <vector>
#include <cctype>
#include <climits>

template <typename T>
class HashTable {
public:
    HashTable() {
        table.resize(1000); // arbitrary starting size, will resize as needed
        count = 0;
    }

    void insert(const std::string& key, T* value) {
        std::string lowerKey = toLower(key);

        // insert all prefixes of the key
        for (int i = 1; i <= lowerKey.size(); i++) {
            std::string prefix = lowerKey.substr(0, i);
            int idx = hashString(prefix);
            bool found = false;

            // check if the prefix already exists in the table
            for (int j = 0; j < table[idx].size(); j++) {
                if (table[idx][j].prefix == prefix) {
                    table[idx][j].results.push_back(value);
                    found = true;
                    break;
                }
            }

            // prefix hasn't been seen before, make a new node
            if (found == false) {
                Node newNode;

                newNode.prefix = prefix;
                newNode.results.push_back(value);
                table[idx].push_back(newNode);

                count++;

                // resize if the number of unique prefixes exceeds the table size
                if (count > table.size()) {
                    resize();
                }
            }
        }
    }

    std::vector<T*> search(const std::string& prefix, int limit) const {
        std::vector<T*> results;

        if (prefix.empty() || limit <= 0) {
            return results;
        }

        std::string lowerPrefix = toLower(prefix);
        int idx = hashString(lowerPrefix);

        for (int i = 0; i < table[idx].size(); i++) {
            if (table[idx][i].prefix == lowerPrefix) {
                for (int j = 0; j < table[idx][i].results.size(); j++) {

                    // break loop if we've reached the limit
                    if (j >= limit) {
                        break;
                    }
                    results.push_back(table[idx][i].results[j]);
                }
                break; // prefix is found
            }
        }

        return results;
    }
    
    std::vector<T*> search(const std::string& prefix) const {
        return search(prefix, INT_MAX);
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