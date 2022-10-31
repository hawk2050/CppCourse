/*
 *	Digit.cpp
 *		Template for overloaded increment operators exercise.
 */
#include <iostream>
using namespace std;

class Digit
{
public:
    Digit(int nDigit=0)
    {
        digit = nDigit % 10;
    }

    Digit operator++();         // prefix
    Digit operator++(int);		// postfix
    Digit operator--(); //prefix

    int getDigit() const { return digit; }
    
     /*This externally defined function needs to be declared as a friend function within the class*/
   friend std::ostream& operator<<(std::ostream& os, const Digit& m); 

private:
    int digit;
};

/*Pre-increment signature*/
Digit Digit::operator++()
{
    this->digit = (this->digit + 1) % 10;
    return *this;
}

/*Post-increment signature, don't use the int*/
Digit Digit::operator++(int)
{
    Digit temp(this->digit);
    this->digit = (this->digit + 1) % 10;
    return temp;
}

ostream& operator<<(ostream& out, const Digit& d)
{
         out << d.getDigit();
         return out;
}

int main()
{
    Digit d = 7;	// Implicit constructor call

    cout << d << endl;		// Print 7
    cout << ++d << endl;	// Print 8, add 1 to the thing, return it.
    cout << d++ << endl;	// Print 8, store the old value, increment the thing, return the old value
    cout << d << endl;		// Print 9
    ++d;
    cout << d << endl;		// Print 0

    //cin.get();
    return 0;
}
