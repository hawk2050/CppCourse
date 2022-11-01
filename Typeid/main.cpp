/*
 *  TypeID_stub.cpp
 *      Stub for typeid exercises.
 */
#include <iostream>
#include <typeinfo>
#include <string>

namespace RCC
{
class A
{
public:
    A(){};
    
};
}
// ------------------------------------
int main()
{
    bool b;
    char c;
    short sh;
    int i;
    long l;
    float f;
    double d;
    std::string s;
    
    RCC::A a;
    
    std::cout << "Different types" << '\n';
    std::cout << "b: " << typeid(b).name() << '\n';
    std::cout << "c: " << typeid(c).name() << '\n';
    std::cout << "sh: " << typeid(sh).name()<< '\n';
    std::cout << "i: " << typeid(i).name() << '\n';
    std::cout << "l: " << typeid(l).name() << '\n';
    std::cout << "f: " << typeid(f).name() << '\n';
    std::cout << "d: " << typeid(d).name() << '\n';
    std::cout << "s: " << typeid(s).name() << '\n';
    std::cout << "A: " << typeid(a).name() << '\n';

    return 0;
}
