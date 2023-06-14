//
// Created by חי כרמי on 14/06/2023.
//

#include "exceptionCity.h"


void exceptionCity::handle() const {
    cout<<"Exception in City <"<<city_name<<'>'<<endl;
    cout<<problem<<endl;
}
