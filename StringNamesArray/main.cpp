/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    array<string,5> names;
    const string myname = "Richard";
    for(size_t j=0; j< 5; ++j)
    {
        cout << j << ": Please enter your first name: ";
        getline(cin,names[j]);
        /*Print Last, First name*/
        
    }
    
    for(size_t j=0; j< names.size(); ++j)
    {
        if(!names[j].empty())
        {
            string::size_type space_pos;
            /*Find the start place of the Last name*/
            space_pos = names[j].find(" ");
            /*Check that a space was found*/
            if( space_pos != string::npos)
            {
                //space_pos also gives a character count for the first name
                cout << names[j].substr(space_pos+1) << ", " << names[j].substr(0, space_pos) << endl;
            }
            
        }
    }
 
    return 0;
}
