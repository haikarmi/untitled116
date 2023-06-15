//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_EXCEPTIONREP_H
#define UNTITLED116_EXCEPTIONREP_H


#include "exception.h"

class exceptionRep: public Exception {
private:
    string name;
public:
    exceptionRep(const string &problem, const string name): Exception(problem),name(name){};
    virtual void handle() const;

};


#endif //UNTITLED116_EXCEPTIONREP_H
