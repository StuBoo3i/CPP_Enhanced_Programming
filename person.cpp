//
// Created by Frank on 2024/1/7.
//

#include "person.h"
#include <iostream>
using namespace std;

//类模板成员函数类外实现
template<class T1,class T2>person<T1,T2>::person(T1 name, T2 age){
    this->name =name;
    this->age = age;
}