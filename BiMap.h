//
// Created by חי כרמי on 12/06/2023.
//

#ifndef UNTITLED116_BIMAP_H
#define UNTITLED116_BIMAP_H

#include <iostream>
#include <map>
using namespace std;

template <typename keyT, typename valueT>

class BiMap {
private:

    map<keyT, valueT> map_first;
    map<valueT, keyT> second;

public:
    BiMap();
    ~BiMap();
    const bool insert(const keyT& key, const valueT& value);
    bool insert(const valueT& value, const keyT& key);
    bool search(const keyT& key, const valueT& value);
    bool erase(const keyT& key);
    bool erase(const valueT& value);
    valueT& operator[](const keyT& key);
    keyT& operator[](const valueT& value);
    int size();
    void print_map();
    class iteratorF {
    private:
        typename map<keyT, valueT>::iterator it;

    public:
        iteratorF(typename map<keyT, valueT>::iterator iterator) : it(iterator) {}

        iteratorF& operator++() {
            it++;
            return *this;
        }

        pair<const keyT, valueT>& operator*() const {
            return *it;
        }
        pair<const keyT, valueT>& operator->() const {
            return (it->second);
        }

        bool operator==(const iteratorF& other) const {
            return it == other.it;
        }

        bool operator!=(const iteratorF& other) const {
            return !(*this == other);
        }
    };

    class iteratorS {
    private:
        typename map<valueT, keyT>::iterator it;

    public:
        iteratorS(typename map<valueT, keyT>::iterator iterator) : it(iterator) {}

        iteratorS& operator++() {
            it++;
            return *this;
        }

        pair<const valueT, keyT>& operator*() const {
            return *it;
        }
        pair<const keyT, valueT>& operator->() const {
            return (it->second);
        }

        bool operator==(const iteratorS& other) const {
            return it == other.it;
        }

        bool operator!=(const iteratorS& other) const {
            return !(*this == other);
        }
    };

    iteratorF beginF() {
        return iteratorF(map_first.begin());
    }

    iteratorF endF() {
        return iteratorF(map_first.end());
    }

    iteratorS beginS() {
        return iteratorS(second.begin());
    }

    iteratorS endS() {
        return iteratorS(second.end());
    }
};



template <typename keyT, typename valueT>
BiMap<keyT, valueT>::BiMap() {

}

template <typename keyT, typename valueT>
BiMap<keyT, valueT>::~BiMap() {
    map_first.clear();
    second.clear();
}
template <typename First,typename Second>
const bool BiMap<First,Second>::insert(const First& key, const Second& value)
{
    for(const auto& pair : map_first) {
        if (pair.first == key) {
            for (const auto& pair2: map_first) {
                if (pair2.second == value)
                    return false;
            }
            second.erase(pair.second);
            map_first[key] = value;
            second[value] = key;
            return true;
        } else if (pair.second == value) {
            for (const auto& pair2: map_first) {
                if (pair2.first == key)
                    return false;
            }
            map_first.erase(pair.first);
            second[value] = key;
            map_first[key] = value;
            return true;

        }
    }
    map_first[key]=value;
    second[value]=key;
    return true;
}


template <typename First,typename Second>
bool BiMap<First,Second>::insert(const Second &key, const First &value) {
    for(const auto& pair : second) {
        if (pair.first == key) {
            for (const auto& pair: map_first) {
                if (pair.second == value)
                    return false;
            }
            map_first.erase(pair.second);
            second[key] = value;
            map_first[value] = key;
            return true;
        } else if (pair.second == value) {
            for (const auto& pair: second) {
                if (pair.first == key)
                    return false;
            }
            second.erase(pair.first);
            map_first[value] = key;
            second[key] = value;
            return true;

        }
    }
    second[key]=value;
    map_first[value]=key;
    return true;
}

template <typename keyT, typename valueT>
bool BiMap<keyT, valueT>::search(const keyT& key, const valueT& value) {
    for (const auto& pair : map_first) {
        if (pair.first == key && pair.second == value) {
            return true;
        }
    }

    for (const auto& pair : second) {
        if (pair.second == key && pair.first == value) {
            return true;
        }
    }
    return false;
}

template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const keyT& key) {
    auto keyIt = map_first.find(key);
    if (keyIt != map_first.end()) {
        valueT value = keyIt->second;
        map_first.erase(keyIt);
        second.erase(value);
        return true;
    }
    return false;
}

template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const valueT& value) {
    auto valueIt = second.find(value);
    if (valueIt != second.end()) {
        keyT key = valueIt->second;
        second.erase(valueIt);
        map_first.erase(key);
        return true;
    }
    return false;
}

template<typename keyT, typename valueT>
valueT& BiMap<keyT, valueT>::operator[](const keyT& key) {

    return map_first[key];
}

template<typename keyT, typename valueT>
keyT& BiMap<keyT, valueT>::operator[](const valueT& value) {

    return second[value];
}
template<typename keyT, typename valueT>
int BiMap<keyT, valueT>::size() {
    int count=0;
    for (const auto& pair : second) {
        ++count;
    }
    return count;

}

template<typename keyT, typename valueT>
void BiMap<keyT, valueT>::print_map() {

   cout << map_first << endl;
   cout << second << endl;
}

#endif //UNTITLED116_BIMAP_H
