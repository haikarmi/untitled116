//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_EXCEPTION_H
#define UNTITLED116_EXCEPTION_H
#include <string>
using namespace std;


class Exception {
protected:
    string problem;

public:
    Exception(const string &problem);

    virtual void handle()const =0; // abstract object

};


#endif //UNTITLED116_EXCEPTION_H
