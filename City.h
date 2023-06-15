//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_CITY_H
#define UNTITLED116_CITY_H
using namespace std;
#include <iostream>
#include <string>

template<typename T>
class City {
private:
    string city_name;
     int city_size;
    T city_id;

public:
    City(const string &name, int size, const T &id);

    ~City();

    City(const City &other);

    City &operator=(const City &other);
    bool operator!=(const City<T>& other) const;
    bool operator== (const City<T>&other)const;
    T operator<(const City<T>& other) const;

    friend std::ostream& operator<<(std::ostream& out, const City<T>& city) {
        out << "The city name is: " << city.city_name << std::endl;
        out << "The city size is: " << city.city_size << std::endl;
        out << "The  city id is: " << city.city_id << std::endl;
        return out;
    }
    friend std::istream& operator>>(std::istream& is, City<T>& city) {
        std::cout << "Enter  name of the city: ";
        is >> city.city_name;
        std::cout << "Enter  size of the city: ";
        is >> city.city_size;
        std::cout << "Enter id of the city: ";
        is >> city.city_id;
        return is;
    }



    const string &getCityName() const {
        return city_name;
    }

    int getCitySize() const {
        return city_size;
    }

    const T &getCityId() const {
        return city_id;
    }

    City();
};

template<typename T>
City<T>::City(const string &name, int size, const T &id) {
    this->city_name = name;
    this->city_size = size;
    this->city_id = id;
}

template<typename T>
City<T>::~City() {}

template<typename T>
City<T>::City(const City &other) {
    this->city_name= other.city_name;
    this->city_size = other.city_size;
    this->city_id = other.city_id;
}

template<typename T>
City<T> &City<T>::operator=(const City &other) {
    if (this != &other) {
        this->city_name = other.city_name;
        this->city_id = other.city_id;
        this->city_size = other.city_size;
    }
    return *this;
}
template<typename T>
bool City<T>::operator!=(const City<T>& other) const {
    return this->city_id != other.city_id;
}

template<typename T>
bool City<T>::operator==(const City<T> &other) const {
    return(this->city_id==other.city_id);
}
template<class T>
T City<T>::operator<(const City<T>& other) const {
    if (city_id < other.city_id) {
        return city_id;
    }
    else {
        return other.city_id;
    }
}

template<typename T>
City<T>::City() {
    this->city_name="no city";
    this->city_id=00000;
    this->city_size=0000;

}


#endif //UNTITLED116_CITY_H
