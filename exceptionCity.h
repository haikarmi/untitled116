//
// Created by חי כרמי on 14/06/2023.
//

#ifndef UNTITLED116_EXCEPTIONCITY_H
#define UNTITLED116_EXCEPTIONCITY_H
#include "exception.h"
#include <iostream>




class exceptionCity: public Exception {
private:
    string city_name;
public:
    exceptionCity(const string &problem, const string city_name):Exception(problem),city_name(city_name){};
  virtual  void handle() const;

};

#endif //UNTITLED116_EXCEPTIONCITY_H
