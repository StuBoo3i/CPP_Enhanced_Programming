//1.3.7 第二种解决方法
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
//类模板成员函数类外实现
template<class T1,class T2>person<T1,T2>::person(T1 name, T2 age){
    this->name =name;
    this->age = age;
}