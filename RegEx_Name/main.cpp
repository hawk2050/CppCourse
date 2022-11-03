/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string name;
    std::regex pattern{"Richard",std::regex_constants::icase};
    
    cout << "Please enter your name:";
    cin >> name;
    
    if(std::regex_search(name,pattern))
    {
        cout << "Welcome " << name << endl;
    }
    else
    {
        cout << "Not interested" << endl;
    }

    return 0;
}
