/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    const string myname = "Richard";
    cout << "Please enter your name:";
    cin >> name;
    
    if(name == myname)
    {
        cout << "Welcome " << myname << endl;
    }
    else
    {
        cout << "Not interested" << endl;
    }

    return 0;
}
