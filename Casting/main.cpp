/*
 *  casting.cpp
 *      Stub for casting exercises
 */
#include <iostream>

// ------------------------------------
int main()
{
    int i;
    double d = 3.1415926;

    i = static_cast<int>(d);
    //i = d;
    std::cout << d << ' ' << i << '\n';

	return 0;
}
