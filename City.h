//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_CITY_H
#define UNTITLED116_CITY_H

#include <iostream>  // Include the necessary header for input/output operations
#include <string>    // Include the necessary header for string manipulation

using namespace std;

template<typename T>
class City {
private:
    string city_name;  // Name of the city
    int city_size;     // Size of the city
    T city_id;         // ID of the city

public:
    City(const string& name, int size, const T& id);  // Constructor

    ~City();  // Destructor

    City(const City& other);  // Copy constructor

    City& operator=(const City& other);  // Assignment operator

    bool operator!=(const City<T>& other) const;  // Inequality operator

    bool operator==(const City<T>& other) const;  // Equality operator

    bool operator<(const City<T>& other) const;   // Less than operator

    friend std::ostream& operator<<(std::ostream& out, const City<T>& city) {
        out << '[' << city.city_id << "] " << city.city_name << " " << city.city_size << " " << endl;

        return out;
    }

    friend std::istream& operator>>(std::istream& is, City<T>& city) {
        is >> city.city_name;  // Read the city_name from the input stream
        is >> city.city_size;  // Read the city_size from the input stream
        is >> city.city_id;    // Read the city_id from the input stream
        return is;
    }

    const string& getCityName() const;  // Getter for city_name

    int getCitySize() const;  // Getter for city_size

    const T& getCityId() const;  // Getter for city_id

    City();  // Default constructor
};

template<typename T>
City<T>::City(const string& name, int size, const T& id) {
    this->city_name = name;  // Assign the provided name to the city_name member variable
    this->city_size = size;  // Assign the provided size to the city_size member variable
    this->city_id = id;      // Assign the provided id to the city_id member variable
}

template<typename T>
City<T>::~City() {}  // Destructor (empty implementation)

template<typename T>
City<T>::City(const City& other) {
    this->city_name = other.city_name;  // Copy the city_name from the other object
    this->city_size = other.city_size;  // Copy the city_size from the other object
    this->city_id = other.city_id;      // Copy the city_id from the other object
}

template<typename T>
City<T>& City<T>::operator=(const City& other) {
    if (this != &other) {
        this->city_name = other.city_name;  // Copy the city_name from the other object
        this->city_id = other.city_id;      // Copy the city_id from the other object
        this->city_size = other.city_size;  // Copy the city_size from the other object
    }
    return *this;
}

template<typename T>
bool City<T>::operator!=(const City<T>& other) const {
    return this->city_id != other.city_id;  // Check if the city_id is not equal to the other object's city_id
}

template<typename T>
bool City<T>::operator==(const City<T>& other) const {
    return (this->city_id == other.city_id);  // Check if the city_id is equal to the other object's city_id
}

template<typename T>
bool City<T>::operator<(const City<T>& other) const {
    return this->city_id < other.city_id;  // Compare the city_id with the other object's city_id
}

template<typename T>
const string& City<T>::getCityName() const {
    return city_name;  // Return the city_name member variable
}

template<typename T>
int City<T>::getCitySize() const {
    return city_size;  // Return the city_size member variable
}

template<typename T>
const T& City<T>::getCityId() const {
    return city_id;  // Return the city_id member variable
}

template<typename T>
City<T>::City() {
    this->city_name = "no city";  // Set a default value for city_name
    this->city_id = 00000;        // Set a default value for city_id
    this->city_size = 0000;       // Set a default value for city_size
}

#endif //UNTITLED116_CITY_H
