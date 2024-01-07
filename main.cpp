#include <iostream>
#include <vector>
#include <algorithm>
#include "Template_Class.h"
//1.3.7
//#include "person.cpp"
#include "person.hpp"
#include "vector.h"
using namespace std;

//1.2.1
void swapInt(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}
//
template<typename T> //声明模板的使用，T为通用类型
void mySwap( T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template<class T>
void function(){
    cout<<"cc"<<endl;
}
int myAdd(int a,int b){
    cout<<"normal function called!  ";return a + b;
}
//1.2.4
template<class T>
T myAdd2(T a,T b){
    return a+b;
}
//1.2.5
template<class T>
T myAdd(T a,T b){
    cout<<"T function called!  ";    return a+b;
}
template<class T>
T myAdd(T a,T b,T c){
    cout<<"T3 function called!  ";    return a+b;
}
//1.2.6
//对比代码
class Person{
public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    void show(){
        cout<< "this->name="<<this->name<<"  this->age="<<this->age<<endl;
    }
    string name;
    int age;
};
template<class T>
bool myCompare(T &a,T &b){
    if (a==b){
        return true;
    }
    return false;
}
//利用具体化的Person版本，具体化优先调用
template<>bool myCompare(Person &a,Person &b) {
    if (a.age==b.age&&a.name == b.name){
        return true;
    }
    return false;
}


void test01(){
    int a = 10,b = 20;

    swapInt(a,b);
    //1.
    mySwap(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;
    //2.
    mySwap<int>(a,b);
    cout<<"a:"<<a<<" b:"<<b<<endl;

    double c = 1.22, d = 2.34;
    swapDouble(c,d);
    mySwap(c,d);
    cout<<"c:"<<c<<" d:"<<d<<endl;

    //1.2.2
    //mySwap(a,c);//错误，类型不一致！

    //function();//无法调用，编译器无法推导数据类型
//    function<int>();//可以执行，数据类型确定。

    //1.2.4
    cout<<"-------------1.2.4------------------"<<endl;
    char e = 'e',f = 'f';
    cout<<myAdd(a,e)<< endl;        //隐式类型转换
    //cout<<myAdd2(a,e)<< endl;         //自动类型推导
    cout<<myAdd2<int>(a,e)<< endl;  //显示选择方式

    //1.2.5
    cout<<"-------------1.2.5------------------"<<endl;
    cout<<myAdd<int>(a,e)<< endl;
    cout<<myAdd(a,e)<< endl;

    //通过空模板的参数列表，强制调用函数模板
    cout<<myAdd<>(a,b)<< endl;
    //函数模板的重载
    cout<<myAdd(a,b,100)<< endl;
    //如果函数模板可以产生更好的匹配，优先调用函数模板
    cout<<myAdd(e,f)<< endl;
    //1.2.6
    cout<<"-------------1.2.6------------------"<<endl;
    bool ret = myCompare(a,b);
    if(ret){
        cout<<"a==b"<<endl;
    }else{
        cout<<"a!=b"<<endl;
    }

    Person p1("Tom",10);
    Person p2("Tom",10);
    bool ret2 = myCompare(p1,p2);
    if(ret2){
        cout<<"p1==p2"<<endl;
    }else{
        cout<<"p1!=p2"<<endl;
    }

}
void test02(){
    //1.3.1
    cout<<"-------------1.3.1------------------"<<endl;
    tPerson<string,int> p1("John",999);
    p1.show();
    //1.3.2
    cout<<"-------------1.3.2------------------"<<endl;
    tPerson p2("John",999);  //该编译器支撑类模板的自动类型推导！！！
    p2.show();
    tPerson<string> p3("Tom",999);
    p3.show();
    //1.3.4
    cout<<"-------------1.3.4------------------"<<endl;
    t_test01();
    t_test02();
    t_test03();
    cout<<"-------------1.3.5------------------"<<endl;
    t_test04();
    cout<<"-------------1.3.6------------------"<<endl;
    tPerson2 <string,int> s1("Ace",20);
    s1.show();
    cout<<"-------------1.3.7------------------"<<endl;
    person <string,int> s2("Ace",20);
    s2.show();
    cout<<"-------------1.3.8------------------"<<endl;
    tPerson3 <string,int> s3("Ace",20);
    print(s3);
    print2(s3);
}
void  test03(){
    cout<<"-------------2.5.1------------------"<<endl;
    v_test01();
    cout<<"-------------2.5.2------------------"<<endl;
    v_test02();
    cout<<"-------------2.5.3------------------"<<endl;
    v_test03();
}
#include "string.h"
void test04(){
    cout<<"-------------3.1.2------------------"<<endl;
    s_test01();
    cout<<"-------------3.1.3------------------"<<endl;
    s_test02();
    cout<<"-------------3.1.4------------------"<<endl;
    s_test03();
}
void test(){
    test04();
    //test03();
    //test02();
    //test01();
}
int main() {
    test();
    return 0;
}
