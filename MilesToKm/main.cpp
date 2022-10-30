/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
Write a program to print out a table of nautical mile to kilometres.
The conversion factor is 1 nautical mile is 1,852 metres.
The program will run something like this:
Nautical Miles
1
2
...
20
Kilometres
1.852
3.704
37.040
*/
#include <iostream>
//#include <string>
#include <ios>
#include <iomanip>

/*Compile time determination of conversion table extent*/
const uint32_t DISTANCE_START_MILE = 1;
const uint32_t DISTANCE_END_MILE =20;
const uint32_t DISTANCE_STEP = 1;
const float conv_factor = 1.852;

using namespace std;

int main(void)
{
    cout << std::setw(16) << std::left << "Nautical Miles" << "Kilometres" << endl;
    for(size_t mile = DISTANCE_START_MILE; mile <= DISTANCE_END_MILE; mile += DISTANCE_STEP)
    {
        cout << std::setw(16) << std::left << mile << mile * conv_factor << endl;
    }
    

}
