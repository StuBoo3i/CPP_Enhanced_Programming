//
// Created by Frank on 2024/1/7.
//

#ifndef STUDY3_STRING_H
#define STUDY3_STRING_H
#include <string>
using namespace std;
//3.1.2
void s_test01(){
    string s1;//默认构造
    const char * str = "Hello World!";
    string s2(str);
    cout<<s2<<endl;
    string s3(s2);
    cout<<s3<<endl;
    string s4(10,'a');
    cout<<s4<<endl;
}
//3.1.3
void s_test02(){
    string str1 = "Hello World";
    string str2 = str1;
    //string str3 = 'a';
    string str4;
    str4.assign("Hello C++");
    string str5;
    str5.assign("Hello C++",5);
    string str6;
    str6.assign(10,'s');
    cout<<str1<<endl<<str2<<endl<<str4<<endl<<str5<<endl<<str6<<endl;
}
//string append.
void s_test03(){
    string str1 = "Hello World";
    str1 += " timing";
    cout<<str1<<endl;
    str1 += ':';
    cout<<str1<<endl;
    string str2 = " LOL DNF";
    str1 += str2;
    cout<<str1<<endl;
    str1.append(" love");
    cout<<str1<<endl;
    str1.append(" game asi",5);
    cout<<str1<<endl;
    str1.append(str2);
    cout<<str1<<endl;
    str1.append(str2,0,4);
    cout<<str1<<endl;
}


#endif //STUDY3_STRING_H
