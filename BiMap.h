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

    map<keyT, valueT> MyMapFirst;
    map<valueT, keyT> MyMapSecond;

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
    class iteratorF {
    private:
        typename map<keyT, valueT>::iterator it;

    public:
        iteratorF(typename map<keyT, valueT>::iterator iterator) : it(iterator) {}

        iteratorF& operator++() {
            ++it;
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
            ++it;
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
        return iteratorF(MyMapFirst.begin());
    }

    iteratorF endF() {
        return iteratorF(MyMapFirst.end());
    }

    iteratorS beginS() {
        return iteratorS(MyMapSecond.begin());
    }

    iteratorS endS() {
        return iteratorS(MyMapSecond.end());
    }
};



template <typename keyT, typename valueT>
BiMap<keyT, valueT>::BiMap() {

}

template <typename keyT, typename valueT>
BiMap<keyT, valueT>::~BiMap() {
    MyMapFirst.clear();
    MyMapSecond.clear();
}
template <typename First,typename Second>
const bool BiMap<First,Second>::insert(const First& key, const Second& value)
{
    for(const auto& pair : MyMapFirst) {
        if (pair.first == key) {
            for (const auto& pair2: MyMapFirst) {
                if (pair2.second == value)
                    return false;
            }
            MyMapSecond.erase(pair.second);
            //revMap[pair.second] = nullptr;
            MyMapFirst[key] = value;
            MyMapSecond[value] = key;
            //++sizeMap;
            return true;
        } else if (pair.second == value) {
            for (const auto& pair2: MyMapFirst) {
                if (pair2.first == key)
                    return false;
            }
            MyMapFirst.erase(pair.first);
            MyMapSecond[value] = key;
            MyMapFirst[key] = value;
            return true;

        }
    }
    MyMapFirst[key]=value;
    MyMapSecond[value]=key;
    return true;
}


template <typename First,typename Second>
bool BiMap<First,Second>::insert(const Second &key, const First &value) {
    for(const auto& pair : MyMapSecond) {
        if (pair.first == key) {
            for (const auto& pair: MyMapSecond) {
                if (pair.second == value)
                    return false;
            }
            MyMapFirst.erase(pair.second);
            //revMap[pair.second] = nullptr;
            MyMapSecond[key] = value;
            MyMapFirst[value] = key;
            //++sizeMap;
            return true;
        } else if (pair.second == value) {
            for (const auto& pair: MyMapSecond) {
                if (pair.first == key)
                    return false;
            }
            MyMapSecond.erase(pair.first);
            //Map[pair.first] = nullptr;
            MyMapFirst[value] = key;
            MyMapSecond[key] = value;
            //++sizeMap;
            return true;

        }
    }
    MyMapSecond[key]=value;
    MyMapFirst[value]=key;
    //++sizeMap;
    return true;
}

template <typename keyT, typename valueT>
bool BiMap<keyT, valueT>::search(const keyT& key, const valueT& value) {
    for (const auto& pair : MyMapFirst) {
        if (pair.first == key && pair.second == value) {
            return true;
        }
    }

    for (const auto& pair : MyMapSecond) {
        if (pair.second == key && pair.first == value) {
            return true;
        }
    }
    return false;
}

template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const keyT& key) {
    auto keyIt = MyMapFirst.find(key);
    if (keyIt != MyMapFirst.end()) {
        valueT value = keyIt->second;
        MyMapFirst.erase(keyIt);
        MyMapSecond.erase(value);
        return true;
    }
    return false;
}

template<typename keyT, typename valueT>
bool BiMap<keyT, valueT>::erase(const valueT& value) {
    auto valueIt = MyMapSecond.find(value);
    if (valueIt != MyMapSecond.end()) {
        keyT key = valueIt->second;
        MyMapSecond.erase(valueIt);
        MyMapFirst.erase(key);
        return true;
    }
    return false;
}

template<typename keyT, typename valueT>
valueT& BiMap<keyT, valueT>::operator[](const keyT& key) {

    return MyMapFirst[key];
}

template<typename keyT, typename valueT>
keyT& BiMap<keyT, valueT>::operator[](const valueT& value) {

    return MyMapSecond[value];
}
template<typename keyT, typename valueT>
int BiMap<keyT, valueT>::size() {
    int count=0;
    for (const auto& pair : MyMapSecond) {
        ++count;
    }
    return count;

}

#endif //UNTITLED116_BIMAP_H
