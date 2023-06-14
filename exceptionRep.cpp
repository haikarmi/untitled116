//
// Created by חי כרמי on 14/06/2023.
//

#include "exceptionRep.h"
using namespace std;
#include <iostream>

void exceptionRep::handle() const {
    cout<<"This exception in regarding  <"<<name <<'>'<<endl;
    cout<<problem<<endl;
}

