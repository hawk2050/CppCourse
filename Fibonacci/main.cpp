/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "fibonacci.hpp"

using namespace std;



int main()
{
    Fibonacci *fibo;
    fibo = new Fibonacci();
    uint32_t number = 0;
    uint32_t sum = 0;
    
    while(number < 1000)
    {
        number = fibo->getNext();
        cout << number<< endl;
        if(number < 1000)
        {
            sum +=number;
        }
    } 
    
    cout << "sum = " << sum << endl;

    return 0;
}