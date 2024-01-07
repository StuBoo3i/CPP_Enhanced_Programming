//
// Created by Frank on 2024/1/7.
//

#ifndef STUDY3_TEMPLATE_CLASS_H
#define STUDY3_TEMPLATE_CLASS_H
#include <iostream>
using namespace std;
//1.3.2 类模板可以指定默认类型
template <class NameType, class AgeType = int>
class tPerson {
public:
    tPerson(NameType name, AgeType age){
        this->name =name;
        this->age = age;
    }
    void show(){
        cout<< "this->name="<<this->name<<"  this->age="<<this->age<<endl;
    }
    NameType name;
    AgeType age;
};
//1.3.4
//1.指定传入类型
void printP1(tPerson<string,int> &p){
    p.show();
}
void t_test01(){
    tPerson<string,int> p1("John",999);
    printP1(p1);
}
//2.参数模板化
template <class NameType, class AgeType>
void printP2(tPerson<NameType, AgeType> &p){
    p.show();
    cout<<"NameType:"<< typeid(NameType).name()<<"  AgeType:"<< typeid(AgeType).name()<<endl;
}
void t_test02(){
    tPerson<string,int> p1("Tom",80);
    printP2(p1);
}
//3.整个类模板化
template <class T>
void printP3(T &p){
    p.show();
    cout<<"T_Type:"<< typeid(T).name()<<endl;
}
void t_test03(){
    tPerson<string,int> p1("Ace",20);
    printP3(p1);
}
//1.3.5
template<class T>
class Base{
public:
    T m;
};

//class Son:public Base  //error！
class Son:public Base<int>{

};
//如果想灵活指定父类中的T的类型，子类也需变为类模板
template<class T1,class T2> class Son2:public Base<T1>{
public:
    Son2(){
        cout<<"T1:"<< typeid(T1).name()<<"  T2:"<< typeid(T2).name()<<endl;
    }
    T2 obj;
};
void t_test04(){
    Son s1;
    Son2<int,char>s2;
}
//1.3.6
template <class NameType, class AgeType = int>
class tPerson2 {
public:
    tPerson2(NameType name, AgeType age);
    void show(){
        cout<< "name="<<this->name<<"  age="<<this->age<<endl;
    }
    NameType name;
    AgeType age;
};
//类模板成员函数类外实现
template<class T1,class T2>
tPerson2<T1,T2>::tPerson2(T1 name, T2 age){
    this->name =name;
    this->age = age;
}
//1.3.8
template <class NameType, class AgeType>
class tPerson3;
//通过全局函数打印信息
template <class NameType, class AgeType>void print2(tPerson3<NameType, AgeType> &p){
    cout<< "out of class:name="<<p.name<<"  age="<<p.age<<endl;
}
template <class NameType, class AgeType>
class tPerson3 {
    //全局函数 类内实现
    friend void print(tPerson3<NameType, AgeType> &p){
        cout<< "name="<<p.name<<"  age="<<p.age<<endl;
    }
    //全局函数 类内实现,加一个空模板的参数列表指明是一个函数模板,同时要让编译器提前知道函数的存在。
    friend void print2<>(tPerson3<NameType, AgeType> &p);

public:
    tPerson3(NameType name, AgeType age);
    void show(){
        cout<< "name="<<this->name<<"  age="<<this->age<<endl;
    }
private:
    NameType name;
    AgeType age;
};
//类模板成员函数类外实现
template<class T1,class T2>
tPerson3<T1,T2>::tPerson3(T1 name, T2 age){
    this->name =name;
    this->age = age;
}
#endif //STUDY3_TEMPLATE_CLASS_H
