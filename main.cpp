# include <iostream>
# include <string>
# include "BiMap.h"
#include "City.h"
#include <fstream>
#include "exceptionCity.h"
#include "exceptionRep.h"

bool check_name(const string &name);

bool check_city_name(const string &name);
bool check_men_not_city( BiMap<City<long>, string> biamap,string men_name);



using namespace std;

//typedef BiMap<long, string> idNameBiMap;

int main() {

    BiMap<City<long>, string> biamap;
    int choice;
    fstream file_input;
    file_input.open("/Users/haikarmi/Desktop/input.txt", ios::in);
    if (!file_input) {
        cout << "file_input not open" << endl;
    } else {
        cout << "file_input open" << endl;
//        file_input >> choice;
    }
    fstream file_output;
    file_output.open("/Users/haikarmi/Desktop/output.txt", ios::out);
    if (!file_output) {
        cout << "file_output not open" << endl;
    } else {
        cout << " The file_output is open for writing" << endl;
    }
    do {
        file_input>>choice;
    switch (choice) {
        case 1: {
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
            try {
                check_name(men_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }


                City<long> city(city_name, size_city, id_city);
                if (biamap[men_name] == city) {


              City<long> city_dif("difult", size_city, id_city);
                city = city_dif;
            }


            biamap.insert(city, men_name);
//            cout<<biamap[men_name];//TODO CHECK

            file_output << city << endl;
            break;


        }
        case 2: {
            string city_name;
            string men_name;
            long id_city;
            int size_city;
            file_input >> men_name;
            try {
                check_name(men_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            file_input >> id_city;
            file_input >> city_name;
            try {
                check_city_name(city_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            file_input >> size_city;
            City<long> city(city_name, size_city, id_city);

            biamap.insert(men_name, city);
            file_output << city << endl;

            break;


        }
        case 3: {
            long id_city;
            string men;
            City<long> *city;
            city=new City<long>("blibla city",0,0);
            file_input >> id_city;
            for (BiMap<City<long>,string>::iteratorS i =biamap.beginS();i !=biamap.endS();++i) {
                if (*city == i.get_key())
                    men = biamap[i.get_key()];
            }
            biamap.erase(men);


        }
        case 4: {
            string men_name;
            file_input >> men_name;
            try {
                check_name(men_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            biamap.erase(men_name);
            break;
        }
        case 5:{

            string men_name;

            file_input >> men_name;
            try {
                check_name(men_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            try {
                check_men_not_city(biamap,men_name);
            }
            catch (exceptionRep &ex_city){
                ex_city.handle();
            }
              file_output << biamap[men_name] << endl;


            break;


        }
        case 6:{
            string men_name;
            City<long> *city;
            city=new City<long>("blibla city",0,0);

            for (BiMap<City<long>,string>::iteratorS i =biamap.beginS();i !=biamap.endS();++i) {
                if (*city==i.get_key())
                    file_output<<biamap[i.get_key()]<<endl;
            }
            break;

        }
        case 7:{
            long id_city;
            file_input >>id_city;
            City<long> *city;
            city=new City<long>("blibla city",0,0);
            if (biamap.find(*city))
                file_output <<"yes"<<endl;
            else
                file_output <<"no"<<endl;
            break;




        }
        case 8:{

            string men_name;

            file_input >> men_name;
            try {
                check_name(men_name);
            }
            catch (Exception &execp) {
                execp.handle();
            }
            try {
                check_men_not_city(biamap,men_name);
            }
            catch (exceptionRep &ex_city){
                ex_city.handle();
            }
            bool flag= false;
            string what;
            flag=biamap.search((biamap[men_name]),men_name);
            if (flag== true) {
                what="yes";
            } else
                 what="no";
            file_output<<what;

            break;


        }
        case 9:{

           if( biamap.empty()== true)
               file_output<<"empty"<<endl;
           else{
//               for (biamap.beginF() ; it != map_first.end(); ++it) {}


               }

            file_input.close();
            file_output.close();
            break;
        }
        case 11:{
            for (BiMap<City<long>,string>::iteratorS i =biamap.beginS();i !=biamap.endS();++i) {
                biamap.erase(i.get_key());
            }
            break;

            }
        case 12:{
            biamap.clear();
            break;
        }
    }
    } while (choice!=12);
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
bool check_men_not_city( BiMap<City<long>, string> biamap,string men_name){
    if(  biamap[men_name].getCityId()==00000)
        throw exceptionRep("no city to men",men_name);
    return true;


}