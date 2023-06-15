# include <iostream>
# include <string>
# include "BiMap.h"
#include "City.h"
#include <fstream>
#include "exceptionCity.h"
#include "exceptionRep.h"

bool check_name(const string &name);

bool check_city_name(const string &name);


using namespace std;

typedef BiMap<long, string> idNameBiMap;

int main() {

    BiMap<City<long>, string> biamap;
    int choice;
    fstream file_input;
    file_input.open("/Users/haikarmi/CLionProjects/untitled116/input.txt", ios::in);
    if (!file_input) {
        cout << "file_input not open" << endl;
    } else {
        cout << "file_input open" << endl;
        file_input >> choice;
    }


    switch (choice) {
        case 1: {
            fstream file_output;
            file_output.open("/Users/haikarmi/CLionProjects/untitled116/output.txt", ios::out);
            if (!file_output) {
                cout << "file_output not open" << endl;
            } else {
                cout << "file_output open to red" << endl;
            }
            string city_name;
            string men_name;
            long id_city;
            int size_city;
            file_input >> id_city;
            file_input >> city_name;
            try {
                check_city_name(city_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            file_input >> size_city;
            file_input >> men_name;


            City<long> city(city_name, size_city, id_city);

            biamap.insert(city, men_name);
            file_output << city << endl;
            file_input.close();
            file_output.close();
//           cout<< biamap.search(city,"fds");


        }
        case 2: {

        }
    }


    return 0;
}

bool check_name(const string &name) {
    for (int i = 0; i < name.size(); ++i) {
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != '-')
            throw exceptionRep("the name not good", name);
    }
    return true;
}

bool check_city_name(const string &name) {
    for (int i = 0; i < name.size(); ++i) {
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != '-')
            throw exceptionCity("the city name not good", name);
    }
    return true;
}