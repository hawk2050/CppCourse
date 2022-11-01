/*
 *	square.cpp
 *	Stub program for students to complete
 */
#include <iostream>

namespace utils
{

template <class T>
T square(T num)
{
    return num*num;
}

template <class T>
T abs(T num)
{
    if(num < 0)
    {
        return -1*num;
    }
    else
    {
        return num;
    }
}

template <class T>
int sign(T num)
{
    int temp = 0;
    if(num == 0)
    {
        temp = 0;
    }
    if(num < 0)
    {
        temp = -1;
    }
    
    if(num > 0)
    {
        temp = 1;
    }
    
    return temp;
    
}

} //namespace utils

using utils::sign;
using utils::abs;
using utils::square;

int main()
{
    // This will call square(int)
    std::cout << "Answer is " << square(2) << '\n';

    // This will call square(double)
    std::cout << "Answer is " << square(2.1) << '\n';
    
    std::cout << "Answer for abs(-3) is " << abs(-3) << '\n';
    std::cout << "Answer for abs(-3.6) is " << abs(-3) << '\n';
    
    std::cout << "Answer for sign(-3) is " << sign(-3) << '\n';
    std::cout << "Answer for sign(3.6) is " << sign(3.6) << '\n';
    

    return 0;
}
