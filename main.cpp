# include <iostream>
# include <string>
# include "BiMap.h"
#include "City.h"
#include <fstream>
#include "exceptionCity.h"
#include "exceptionRep.h"

bool check_name(const string &name);  // Checks if the given name is valid

bool check_city_name(const string &name);  // Checks if the given city name is valid

bool check_name_not_found(BiMap<City<long>, string> &biamap, string &men_name);  // Checks if the men_name is not found in the BiMap

bool check_city_found(BiMap<City<long>, string> &biamap, City<long> &city);  // Checks if the given city is found in the BiMap

bool check_name_found(BiMap<City<long>, string> &biamap, const string &men_name);  // Checks if the men_name is found in the BiMap

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
                bool flag1 = false, flag2 = false;

                // Create a City object with the given parameters
                City<long> city(city_name, size_city, id_city);

                try {
                    // Check if the men_name is found in biamap
                    flag1 = check_name_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;
                }
                try {
                    // Check if the city is found in biamap
                    flag2 = check_city_found(biamap, city);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;
                }

                // If both flag1 and flag2 are true, insert the city and men_name into biamap
                if (flag1 && flag2) {
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
                bool flag1, flag2;

                // Create a City object with the given parameters
                City<long> city(city_name, size_city, id_city);

                try {
                    // Check if the men_name is found in biamap
                    flag1 = check_name_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;
                }
                try {
                    // Check if the city is found in biamap
                    flag2 = check_city_found(biamap, city);
                }
                catch (Exception &execp) {
                    execp.handle();
                    file_output << "error" << endl;
                }

                // If both flag1 and flag2 are true, insert the city and men_name into biamap
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

                // Create a new City object with a temporary name for comparison
                city = new City<long>("blibla city", 0, id_city);

                // Iterate over the values (strings) in biamap and find the corresponding name for the given city
                for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
                    if (*city == i.get_key())
                        name = biamap[i.get_key()];
                }

                // Erase the name from biamap
                biamap.erase(name);

                // Deallocate memory for the temporary city object
                delete city;
                break;
            }
            case Erase_name: {
                bool flag = false;
                string men_name;
                file_input >> men_name;

                // Validate the men_name using the check_name function
                try {
                    check_name(men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;
                    execp.handle();
                }

                // Check if the men_name is not found in biamap using the check_name_not_found function
                try {
                    flag = check_name_not_found(biamap, men_name);
                }
                catch (Exception &execp) {
                    file_output << "error" << endl;
                    execp.handle();
                }

                // If the men_name is found, erase it from biamap
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

                // Create a temporary city object with a dummy name and the given id_city
                city = new City<long>("blibla city", 0, id_city);

                // Iterate over the biamap to find the corresponding name for the city with the given id_city
                for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
                    if (*city == i.get_key())
                        file_output << biamap[i.get_key()] << endl; // Output the corresponding name to the file
                }

                delete city;
                break;
            }
            case check_city: {
                long id_city;
                file_input >> id_city;

                // Create a temporary city object with a dummy name and the given id_city
                City<long> *city;
                city = new City<long>("blibla city", 0, id_city);

                // Check if the temporary city object is found in the biamap
                if (biamap.find(*city))
                    file_output << "yes the id city is linked to the city on the map" << endl;
                else
                    file_output << "No, it is not linked to the id city on the map" << endl;

                delete city;
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

                // Check if the men_name exists in the biamap
                if (biamap.find(men_name)) {
                    file_output << "yes, the name is in the map" << endl;
                } else {
                    file_output << "No, the name is not in the map" << endl;
                }

                break;
            }
            case sort_City: {
                // Sort the cities in the biamap and write the sorted list to the file_output
                biamap.short_city(file_output);
                break;
            }
            case sort_Name: {
                // Sort the cities in the biamap and write the sorted list to the file_output
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
        // Check if the characters in the name are valid (only alphabets and hyphens)
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != '-')
            throw exceptionRep("The name is not valid", name);
    }
    return true;
}

bool check_city_name(const string &name) {
    for (int i = 0; i < name.size(); ++i) {
        // Check if the characters in the city name are valid (only alphabets and hyphens)
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != '-')
            throw exceptionCity("The city name is not valid", name);
    }
    return true;
}

bool check_name_not_found(BiMap<City<long>, string> &biamap, string &men_name) {
    // Check if the person's name is not found in the BiMap
    if (biamap.find(men_name) == 0) {
        throw exceptionRep("The person is not found", men_name);
    }
    return true;
}



bool check_city_found(BiMap<City<long>, string> &biamap, City<long> & city) {
    City<long> *new_city;
    new_city = new City<long>("blibla city", 0, city.getCityId());

    // Check if the city already exists in the BiMap
    if (biamap.find(city) != 0) {
        throw exceptionCity("The city already exists", city.getCityName());
    }

    // Check if the city ID already exists in the BiMap
    for (BiMap<City<long>, string>::iteratorS i = biamap.beginS(); i != biamap.endS(); ++i) {
        if (*new_city == i.get_key())
            throw exceptionCity("The city ID already exists", city.getCityName());
    }

    return true;
}

bool check_name_found(BiMap<City<long>, string> & biamap, const string &men_name) {
    // Check if the person's name already exists in the BiMap
    if (biamap.find(men_name) != 0) {
        throw exceptionRep("The person's name already exists", men_name);
    }
    return true;
}

