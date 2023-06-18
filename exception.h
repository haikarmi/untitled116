//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_EXCEPTION_H
#define UNTITLED116_EXCEPTION_H

#include <string>
using namespace std;

class Exception {
protected:
    string problem;  // A string that represents the problem or exception

public:
    Exception(const string& problem);  // Constructor that initializes the problem

    virtual void handle() const = 0;  // Abstract method for handling the exception
};

#endif //UNTITLED116_EXCEPTION_H
