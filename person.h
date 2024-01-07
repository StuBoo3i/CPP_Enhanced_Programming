//
// Created by Frank on 2024/1/7.
//

#ifndef STUDY3_PERSON_H
#define STUDY3_PERSON_H
#include <iostream>
using namespace std;

//1.3.7
template <class NameType, class AgeType = int>
class person {
public:
    person(NameType name, AgeType age);
    void show(){
        cout<< "name="<<this->name<<"  age="<<this->age<<endl;
    }
    NameType name;
    AgeType age;
};


#endif //STUDY3_PERSON_H
