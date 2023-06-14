# include <iostream>
# include <string>
# include "BiMap.h"
#include "City.h"
using namespace std;

typedef BiMap<long, string> idNameBiMap;

int main(){

    BiMap <City<long>,string> bli;
    int choice;
    cin>>choice;
    switch (choice) {
        case 1: {
            string name;
            cout << "enter city " << endl;
            cin >> name;
            City<long> bla(name, 400, 33);
            bli.insert(bla, name);
            cout<<bla<<endl;


        }
    }
















//    //A map which the first value is an integer (id number)
//    // and the second is a string (name)
//    idNameBiMap idName;
//
//    bool flag;
//
//    flag = idName.insert (777, "SevenSevenSeven");
//    flag = idName.insert (333, "ThreeThreeThree");
//
//    cout<<idName[999]<<endl;				//
//    cout<<idName[333]<<endl;				//ThreeThreeThree
//    cout<<idName["SevenSevenSeven"]<<endl;		//777
//
//    flag = idName.insert ("ThreeThreeThree", 444);
//    flag = idName.insert (777,"NewValue");
//
//    cout<<idName[333]<<endl;				//
//    cout<<idName[444]<<endl;				//ThreeThreeThree
//    cout<<idName["ThreeThreeThree"]<<endl;		//444
//    cout<<idName[777]<<endl;				//NewValue
//    cout<<idName.size()<<endl;				//2
//
//    flag = idName.insert ("TwoTwoTwo", 222);
//    flag = idName.insert (222, "NewValue");		//illegal value
//
//    cout<<idName[222]<<endl;				//TwoTwoTwo
//
//
//    flag = idName.erase ("NewValue");
//    flag = idName.erase (777);
//    flag = idName.erase (999);
//    flag = idName.erase ("ThreeThreeThree");
//
//    cout<<idName.size()<<endl;				//1
//
//    idNameBiMap::iteratorF iterF = idName.beginF();
//    ++iterF;
//    if (iterF == idName.endF())
//        cout<<"one element"<<endl;			//one element

    return 0;
}
