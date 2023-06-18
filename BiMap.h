//
// Created by חי כרמי on 12/06/2023.
//

#ifndef UNTITLED116_BIMAP_H
#define UNTITLED116_BIMAP_H

#include <iostream>
#include <map>
#include "exceptionRep.h"
#include "exceptionCity.h"
#include <fstream>

using namespace std;

template <typename keyT, typename valueT>
class BiMap {
private:
    map<keyT, valueT> map_first;  // Map for the first set of key-value pairs
    map<valueT, keyT> second;     // Map for the second set of key-value pairs

public:
    BiMap();                     // Default constructor
    ~BiMap();                    // Destructor

    const bool insert(const keyT& key, const valueT& value);   // Insert a key-value pair into the BiMap
    bool insert(const valueT& value, const keyT& key);         // Insert a value-key pair into the BiMap
    bool search(const keyT& key, const valueT& value);         // Check if a given key-value pair exists in the BiMap
    bool erase(const keyT& key);                               // Erase a key-value pair by key
    bool erase(const valueT& value);                           // Erase a key-value pair by value
    valueT& operator[](const keyT& key);                       // Access the value associated with a given key
    keyT& operator[](const valueT& value);                     // Access the key associated with a given value
    void removeById(const keyT& key);                          // Remove a key-value pair by key
    void removeById(const valueT& value);                      // Remove a key-value pair by value
    bool empty();                                               // Check if the BiMap is empty
    bool find(const keyT first) {                               // Check if a given key exists in the BiMap
        return map_first.count(first) != 0;
    }
    bool find(const valueT& val) {                              // Check if a given value exists in the BiMap
        return second.count(val) != 0;
    }
    valueT& at(const keyT& key);                                // Access the value associated with a given key (with bounds checking)
    void clear();                                               // Clear the BiMap
    void short_city(fstream& output_file);                      // Output a list of keys (city) to a file
    void short_rep(fstream& output_file);                       // Output a list of values (rep) to a file

    int size();                                                 // Get the size of the BiMap
    void print_map();                                           // Print the contents of the BiMap

    // Iterator class for iterating over the first set of key-value pairs
    class iteratorF {
    private:
        typename map<keyT, valueT>::iterator it;

    public:
        iteratorF(typename map<keyT, valueT>::iterator iterator) : it(iterator) {}

        iteratorF& operator++() {                              // Pre-increment operator
            it++;
            return *this;
        }

        pair<const keyT, valueT>& operator*() const {          // Dereference operator
            return *it;
        }

        pair<const keyT, valueT>* operator->() const {         // Member access operator
            return &(*it);
        }

        bool operator==(const iteratorF& other) const {        // Equality comparison operator
            return it == other.it;
        }

        bool operator!=(const iteratorF& other) const {        // Inequality comparison operator
            return it != other.it;
        }

        valueT& get_val() {                                    // Access the value associated with the current key-value pair
            return it->first;
        }
    };

    // Iterator class for iterating over the second set of key-value pairs
    class iteratorS {
    private:
        typename map<valueT, keyT>::iterator it;

    public:
        iteratorS(typename map<valueT, keyT>::iterator iterator) : it(iterator) {}

        iteratorS& operator++() {                              // Pre-increment operator
            it++;
            return *this;
        }

        pair<const valueT, keyT>& operator*() const {          // Dereference operator
            return *it;
        }

        pair<const valueT, keyT>* operator->() const {         // Member access operator
            return &(*it);
        }

        bool operator==(const iteratorS& other) const {        // Equality comparison operator
            return it == other.it;
        }

        bool operator!=(const iteratorS& other) const {        // Inequality comparison operator
            return it != other.it;
        }

        keyT& get_key() {                                      // Access the key associated with the current key-value pair
            return it->second;
        }
    };

    iteratorF beginF();                                        // Get an iterator pointing to the beginning of the first set of key-value pairs
    iteratorF endF();                                          // Get an iterator pointing to the end of the first set of key-value pairs
    iteratorS beginS();                                        // Get an iterator pointing to the beginning of the second set of key-value pairs
    iteratorS endS();                                          // Get an iterator pointing to the end of the second set of key-value pairs
};

// Implementation of the BiMap class

// Default constructor
template<typename keyT, typename valueT>
BiMap<keyT, valueT>::BiMap() {}

// Destructor
template<typename keyT, typename valueT>
BiMap<keyT, valueT>::~BiMap() {}

// Insert a key-value pair into the BiMap
template<typename keyT, typename valueT>
const bool BiMap<keyT, valueT>::insert(const keyT& key, const valueT& value) {
    // Insert into the first map
    pair<typename map<keyT, valueT>::iterator, bool> ret_first = map_first.insert(make_pair(key, value));
    if (!ret_first.second) {
        // Key already exists, return false
        return false;
    }

    // Insert into the second map
    pair<typename map<valueT, keyT>::iterator, bool> ret_second = second.insert(make_pair(value, key));
    if (!ret_second.second) {
        // Value already exists, erase the entry from the first map and return false
        map_first.erase(ret_first.first);
        return false;
    }

    return true;
}

// Insert a value-key pair into the BiMap
template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::insert(const valueT& value, const keyT& key) {
    // Insert into the second map
    pair<typename map<valueT, keyT>::iterator, bool> ret_second = second.insert(make_pair(value, key));
    if (!ret_second.second) {
        // Value already exists, return false
        return false;
    }

    // Insert into the first map
    pair<typename map<keyT, valueT>::iterator, bool> ret_first = map_first.insert(make_pair(key, value));
    if (!ret_first.second) {
        // Key already exists, erase the entry from the second map and return false
        second.erase(ret_second.first);
        return false;
    }

    return true;
}

// Check if a given key-value pair exists in the BiMap
template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::search(const keyT& key, const valueT& value) {
    typename map<keyT, valueT>::iterator it_first = map_first.find(key);
    if (it_first == map_first.end()) {
        // Key does not exist, return false
        return false;
    }

    typename map<valueT, keyT>::iterator it_second = second.find(value);
    if (it_second == second.end()) {
        // Value does not exist, return false
        return false;
    }

    // Key and value exist, return true
    return true;
}

// Erase a key-value pair by key
template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const keyT& key) {
    typename map<keyT, valueT>::iterator it_first = map_first.find(key);
    if (it_first == map_first.end()) {
        // Key does not exist, return false
        return false;
    }

    // Erase from the second map
    second.erase(it_first->second);

    // Erase from the first map
    map_first.erase(it_first);
    return true;
}

// Erase a key-value pair by value
template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const valueT& value) {
    typename map<valueT, keyT>::iterator it_second = second.find(value);
    if (it_second == second.end()) {
        // Value does not exist, return false
        return false;
    }

    // Erase from the first map
    map_first.erase(it_second->second);

    // Erase from the second map
    second.erase(it_second);
    return true;
}

// Access the value associated with a given key
template<typename keyT, typename valueT>
valueT& BiMap<keyT, valueT>::operator[](const keyT& key) {
    return map_first[key];
}

// Access the key associated with a given value
template<typename keyT, typename valueT>
keyT& BiMap<keyT, valueT>::operator[](const valueT& value) {
    return second[value];
}

// Remove a key-value pair by key
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::removeById(const keyT& key) {
    erase(key);
}

// Remove a key-value pair by value
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::removeById(const valueT& value) {
    erase(value);
}

// Check if the BiMap is empty
template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::empty() {
    return map_first.empty();
}

// Access the value associated with a given key (with bounds checking)
template<typename keyT, typename valueT>
valueT& BiMap<keyT, valueT>::at(const keyT& key) {
    return map_first.at(key);
}

// Clear the BiMap
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::clear() {
    map_first.clear();
    second.clear();
}

// Output a list of keys (city) to a file
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::short_city(fstream& output_file) {
    for (const auto& entry : map_first) {
        output_file << entry.first << endl;
    }
}

// Output a list of values (rep) to a file
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::short_rep(fstream& output_file) {
    for (const auto& entry : second) {
        output_file << entry.first << endl;
    }
}

// Get the size of the BiMap
template<typename keyT, typename valueT>
int BiMap<keyT, valueT>::size() {
    return map_first.size();
}

// Print the contents of the BiMap
template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::print_map() {
    for (const auto& entry : map_first) {
        cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }
}

// Get an iterator pointing to the beginning of the first set of key-value pairs
template<typename keyT, typename valueT>
typename BiMap<keyT, valueT>::iteratorF BiMap<keyT, valueT>::beginF() {
    return iteratorF(map_first.begin());
}

// Get an iterator pointing to the end of the first set of key-value pairs
template<typename keyT, typename valueT>
typename BiMap<keyT, valueT>::iteratorF BiMap<keyT, valueT>::endF() {
    return iteratorF(map_first.end());
}

// Get an iterator pointing to the beginning of the second set of key-value pairs
template<typename keyT, typename valueT>
typename BiMap<keyT, valueT>::iteratorS BiMap<keyT, valueT>::beginS() {
    return iteratorS(second.begin());
}

// Get an iterator pointing to the end of the second set of key-value pairs
template<typename keyT, typename valueT>
typename BiMap<keyT, valueT>::iteratorS BiMap<keyT, valueT>::endS() {
    return iteratorS(second.end());
}

#endif //UNTITLED116_BIMAP_H
