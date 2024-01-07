//
// Created by Frank on 2024/1/7.
//

#ifndef STUDY3_VECTOR_H
#define STUDY3_VECTOR_H
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//2.5.1
void myPrint(int val){
    cout<<val<<endl;
}
void v_test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(15);

    //vector<int>::iterator itBegin = v.begin();
    auto itBegin = v.begin();//起始迭代器，指向容器的第一个元素。
    //vector<int>::iterator itEnd = v.end();
    auto itEnd = v.end();//结束迭代器，指向容器的最后一个元素的下一个位置。

    //遍历一
    while (itBegin != itEnd){
        cout<<*itBegin<<endl;
        itBegin++;
    }
    //遍历二
    for (auto it = v.begin(); it != v.end() ; it++) {
        cout<<*it<<endl;
    }
    //遍历三
    for_each(v.begin(),v.end(), myPrint);
}
//2.5.2
class vPerson {
public:
    vPerson(string name, int age){
        this->name =name;
        this->age = age;
    }
    void show() const{
        cout<< "this->name="<<this->name<<"  this->age="<<this->age<<endl;
    }
    string name;
    int age;
};
void v_test02(){
    vector<vPerson>v1;
    vPerson p1("Ace",20);
    vPerson p2("Tom",50);
    vPerson p3("John",46);
    vPerson p4("Lice",23);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);

    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout<<"name=" << it->name << "  age=" << it->age << endl;
    }

    vector<vPerson*>v2;
    v2.push_back(&p1);
    v2.push_back(&p2);
    v2.push_back(&p3);
    v2.push_back(&p4);

    for (auto it = v2.begin(); it != v2.end(); it++) {
        cout<<"name=" << (*it)->name<< "  age=" << (*it)->age << endl;
    }
}
//2.5.3
void v_test03(){
    vector< vector<int>>v;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i);
        v2.push_back(i+5);
        v3.push_back(i+10);
        v4.push_back(i+15);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (auto it = v.begin(); it != v.end(); it++ ) {
        //(*it) -- vector<int>
        for (auto item = (*it).begin(); item != (*it).end(); item++ ) {
            cout<<*item<<"\t";
        }
        cout<<endl;
    }
}


#endif //STUDY3_VECTOR_H
