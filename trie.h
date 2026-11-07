//
// Created by zacha on 11/6/2026.
//

#ifndef MUSICAUTOCOMPLETER_TRIE_H
#define MUSICAUTOCOMPLETER_TRIE_H


#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <iostream>

// ------------ Information about trie.h ------------
// the only thing ever recieved from Song Loader is a vector of songs --> vector<SearchEntry> songs;
/* there are two entries:
    - Key: song title OR artist name (user types the prefix)
    - Value: song* artist* themselves. Main builds the "Song - Artist" display for the text and utilizes pointers for more info part of the menu
    - Case-insensitive matching. Results will alphabetically come back for their key order.
    - Songs sharing the same title are ALL returned since they share one node.

    vector<song*> top5 = songTrie.search("smooth", 5);   // 5 matches max
    vector<song*> all  = songTrie.search("smooth"); //  ALL matches
*/

using namespace std;

template <typename T>
class Trie {
private:
    struct Node {
        map<unsigned char, Node*> children; // ordered, so DFS output is alphabetical
        vector<T*> items;                   // everything whose key ends EXACTLY at this node
    };

    Node* root;

    // LOWERCASE COPY --> "Rad", "rad" and "RAD" all hit the same path.
    static string normalize(const string& s) {
        string out = s;
        for (char& c : out) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        return out;
    }

    // DFS on the subtree. maxResults <= 0 -->  "no limit".
    // Returns true once we hit the limit, so that every level stops early.
    bool collect(Node* node, vector<T*>& results, int maxResults) {
        for (T* item : node->items) {
            results.push_back(item);
            if (maxResults > 0 && static_cast<int>(results.size()) >= maxResults) return true;
        }
        for (auto& child : node->children) {
            if (collect(child.second, results, maxResults)) return true;
        }
        return false;
    }

    // Deletes EVERY node ensuring no memory leaks.
    void destroy(Node* node) {
        if (node == nullptr) return;
        for (auto& child : node->children) {
            destroy(child.second);
        }
        delete node;
    }

    // If there's nothing we start with nullptr, else we walkdown the prefix.
    Node* findPrefixNode(const string& prefix) {
        Node* current = root;
        for (char c : normalize(prefix)) {
            auto it = current->children.find(static_cast<unsigned char>(c));
            if (it == current->children.end()) return nullptr;
            current = it->second;
        }
        return current;
    }

public:
    Trie() { root = new Node(); }
    ~Trie() { destroy(root); }

    // RAW Pointers to BLOCK unintentional Copies
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    // Inserting ONE Key (either song title or artist name) with its OBJECT that it belongs to.
    void insert(const string& key, T* value) {
        Node* current = root;
        for (char c : normalize(key)) {
            unsigned char index = static_cast<unsigned char>(c);
            auto it = current->children.find(index);
            if (it == current->children.end()) {
                it = current->children.emplace(index, new Node()).first;
            }
            current = it->second;
        }
        current->items.push_back(value);
    }

    // This goes up to maxResults (5) which main will use.
    vector<T*> search(const string& prefix, int maxResults) {
        vector<T*> results;
        Node* start = findPrefixNode(prefix);
        if (start != nullptr) collect(start, results, maxResults);
        return results;
    }

    // ALL matches.
    vector<T*> search(const string& prefix) {
        return search(prefix, 0);
    }
};


#endif //MUSICAUTOCOMPLETER_TRIE_H

