//
// Created by חי כרמי on 14/06/2023.
//

#include "exceptionCity.h"

void exceptionCity::handle() const {
    cout << "Exception in City <" << city_name << '>' << endl;  // Print the name of the city where the exception occurred
    cout << problem << endl;  // Print the problem description
}
