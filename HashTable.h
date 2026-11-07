#pragma once
#include <string>
#include <vector>

class HashTable {
public:
    HashTable();
    void insert(const std::string& key, const std::string& display);
    std::vector<std::string> search(const std::string& prefix, int limit) const;
    std::vector<std::string> search(const std::string& prefix) const;

private:
    struct Node {
        std::string prefix;
        std::vector<std::string> results; // these are the matching results
    };

    std::vector<std::vector<Node>> table; // the actual hash table
    size_t count;

    int hashString(std::string str) const;
    static std::string toLower(std::string str);
    void resize();
};