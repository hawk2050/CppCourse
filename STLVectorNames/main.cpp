/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> names;
    vector<string>::iterator it;
    string myname;
    const string term = "quit";
    
    while(true)
    {
        cout << "Please enter a name (quit to end): ";
        getline(cin,myname);
        if(myname == term)
        {
            break;
        }
        
        names.push_back(myname);
    }
    
    cout << "The " << names.size() << " entered were: ";
    
    for(it = names.begin(); it != names.end(); ++it)
    {
        cout << *it << " ";
    }
 
    return 0;
}
