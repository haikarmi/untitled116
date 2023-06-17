# include <iostream>
# include <string>
# include "BiMap.h"
#include "City.h"
#include <fstream>
#include "exceptionCity.h"
#include "exceptionRep.h"

bool check_name(const string &name);

bool check_city_name(const string &name);

bool check_men_not_city(BiMap<City<long>, string> &biamap, string &men_name);

bool check_name_not_found(BiMap<City<long>, string> &biamap, string &men_name);

bool check_city_not_found( BiMap<City<long>, string>  &biamap,  City<long> &city);

bool check_city_found(BiMap<City<long>, string> &biamap, City<long> &city);

bool check_name_found(BiMap<City<long>, string> & biamap,const string &men_name);


using namespace std;

typedef enum {Add_city_to_map=1, Add_name_to_map, erase_city, Erase_name, Get_city,Get_name, check_city, check_men, sort_City, sort_Name, Clean, Exit}menu;
int main() {

    BiMap<City<long>, string> biamap;
    int choice;
    fstream file_input;
    file_input.open("/Users/haikarmi/CLionProjects/untitled116/input.txt", ios::in);
    if (!file_input) {
        cout << "file_input not open" << endl;
    } else {
        cout << "file_input open" << endl;
    }
    fstream file_output;
    file_output.open("/Users/haikarmi/CLionProjects/untitled116/output.txt", ios::out);
    if (!file_output) {
        cout << "file_output not open" << endl;
    } else {
        cout << " The file_output is open for writing" << endl;
    }
    do {
        file_input >> choice;
        switch (choice) {
            case Add_city_to_map: {
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
                    file_output << "error" << endl;

                    execp.handle();
                }
                file_input >> size_city;
                file_input >> men_name;
                try {

                    check_name(men_name);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;

                }
                bool flag1= false,flag2= false;


                City<long> city(city_name, size_city, id_city);

                try {
                   flag1= check_name_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;

                }
                try {
                    flag2 = check_city_found(biamap, city);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;

                }
                    if (flag1&&flag2) {
                        biamap.insert(city, men_name);
                    }
                    break;

                }
            case Add_name_to_map: {
                string city_name;
                string men_name;
                long id_city;
                int size_city;
                file_input >> men_name;
                try {
                    check_name(men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;

                    execp.handle();
                }
                file_input >> id_city;
                file_input >> city_name;
                try {
                    check_city_name(city_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;

                    execp.handle();
                }
                file_input >> size_city;
                bool flag1,flag2;


                City<long> city(city_name, size_city, id_city);

                try {
                    flag1= check_name_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;

                }
                try {
                    flag2 = check_city_found(biamap, city);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;

                }
                if (flag1 && flag2) {
                    biamap.insert(city, men_name);
                }

                break;
            }
            case erase_city: {
                long id_city;
                string name;
                City<long> *city;
                file_input >> id_city;
                city = new City<long>("blibla city", 0, id_city);

                for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
                    if (*city == i.get_key())
                        name = biamap[i.get_key()];

                }
                if (biamap.erase(name))
                    cout << "city removed" << endl;
                else {
                    cout << "city not found" << endl;
                }
                delete city;
                break;


            }
            case Erase_name: {
                bool flag = false;
                string men_name;
                file_input >> men_name;
                try {
                    check_name(men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;

                    execp.handle();
                }
                try {
                    flag = check_name_not_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;

                    execp.handle();
                }
                if (flag)
                    biamap.erase(men_name);
                break;
            }
            case Get_city: {
bool flag= false;
                string men_name;

                file_input >> men_name;
                try {
                    check_name(men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;
                    execp.handle();
                }
                try {
                   flag= check_name_not_found(biamap, men_name);
                }
                catch (exceptionRep &ex_city) {
                    file_output << "error" << endl;
                    ex_city.handle();
                }if(flag) {
                    file_output << biamap[men_name] << endl;
                }

                break;


            }
            case Get_name: {
                long id_city;
                City<long> *city;
                file_input >> id_city;

                city = new City<long>("blibla city", 0, id_city);

                for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
                    if (*city == i.get_key())
                        file_output << biamap[i.get_key()] << endl;//todo check
                }
                break;

            }
            case check_city: {
                long id_city;
                file_input >> id_city;
                City<long> *city;
                city = new City<long>("blibla city", 0, id_city);
                if (biamap.find(*city))
                    file_output << "yes the id city is linked to the city on the map" << endl;
                else
                    file_output << "No, Ir is not linked to id city on the map" << endl;
                break;


            }
            case check_men: {

                string men_name;

                file_input >> men_name;
                try {
                    check_name(men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;
                    execp.handle();
                }
                if (biamap.find(men_name)) {
                    file_output << "yes the name in map\n" << endl;
                } else {
                    file_output << "no the name not in map" << endl;

                }


                break;


            }
            case sort_City: {
                biamap.short_city(file_output);
                break;
            }
            case sort_Name: {
                biamap.short_rep(file_output);
                break;
            }
            case Clean: {
                    biamap.clear();
                break;
                }
            case Exit: {
                biamap.clear();
                file_output << " the project closed " << endl;


                break;

            }
            default: {
                file_output << "Not available" << endl;
            }

        }
    } while (choice != 12);
    file_input.close();
    file_output.close();


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

bool check_men_not_city(BiMap<City<long>, string> &biamap, string &men_name) {
    if (biamap[men_name].getCityId() == 00000)
        throw exceptionRep("no city to men", men_name);
    return true;

}

bool check_name_not_found(BiMap<City<long>, string> &biamap, string &men_name) {
    if (biamap.find(men_name) == 0) {
        throw exceptionRep("the men not found", men_name);
    }
    return true;

}

bool check_city_not_found(BiMap<City<long>, string> &biamap, City<long> &city) {
    if (biamap.find(city) == 0) {
        throw exceptionCity("the city not found", city.getCityName());
    }
    return true;

}

bool check_city_found(BiMap<City<long>, string> &biamap, City<long> & city) {
    City<long> *new_city;
    new_city = new City<long>("blibla city", 0, city.getCityId());

    if (biamap.find(city) != 0) {
        throw exceptionCity("The city already exists", city.getCityName());
    }
    for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
        if (*new_city == i.get_key())
            throw exceptionCity("The id city already exists", city.getCityName());

    }


        return true;

}

bool check_name_found(BiMap<City<long>, string> & biamap, const string &men_name) {
    if (biamap.find(men_name) != 0) {
        throw exceptionRep("The person's name already exists", men_name);
    }
    return true;

}

