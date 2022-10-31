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
    cout << "Please enter your first and last names:";
    getline(cin,name);
    
    /*Print Last, First name*/
    
    if(!name.empty())
    {
        string::size_type space_pos;
        /*Find the start place of the Last name*/
        space_pos = name.find(" ");
        /*Check that a space was found*/
        if( space_pos != string::npos)
        {
            //space_pos also gives a character count for the first name
            cout << name.substr(space_pos+1) << ", " << name.substr(0, space_pos) << endl;
        }
        
    }
    

    return 0;
}
