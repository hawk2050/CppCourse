/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

//using People = map<string, unsigned>

int main()
{
    map<string, unsigned> names;
    map<string, unsigned>::iterator it;
    map<string, unsigned>::reverse_iterator r_it;
    string myname;
    const string term = "quit";
    
    while(true)
    {
        cout << "Please enter a name and an age(name age): ";
        getline(cin,myname);
        if(myname == term or myname=="" )
        {
            break;
        }
        
        if(!myname.empty())
        {
            string::size_type space_pos;
            /*Find the start place of the Last name*/
            space_pos = myname.find(" ");
            /*Check that a space was found*/
            if( space_pos != string::npos)
            {
                /*space_pos also gives a character count for the first name
                 * Store name as map key, and age as value
                 * */
                names[myname.substr(0, space_pos)] = stoi(myname.substr(space_pos+1));
                //cout << names[j].substr(space_pos+1) << ", " << names[j].substr(0, space_pos) << endl;
            }
            
        }
        
    }
    
    cout << "The " << names.size() << " entered were: \n";
    
    /*Iterator based for loop*/
    for(it = names.begin(); it != names.end(); ++it)
    {
        cout << it->first << ": " << it->second << '\n';
    }
    
    cout << endl << endl;
    
     /*Reverse Iterator based for loop*/
    for(r_it = names.rbegin(); r_it != names.rend(); ++r_it)
    {
        cout << r_it->first << ": " << r_it->second << '\n';
    }
    
    cout << endl << endl;
   
    /*Using auto don't even have to declare a reverse_iterator!*/
    for(auto t_it = names.rbegin(); t_it != names.rend(); ++t_it)
    {
        cout << t_it->first << ": " << t_it->second << '\n';
    }
#if 0  
    cout << endl << endl;
    /*Range based for loop*/
    for(string name : names)
    {
        cout << name << " ";
    }
    
    cout << endl << endl;
    
    /*Range based for loop*/
    std::string_view sep = "";
    for(string name : names)
    {
        cout << sep << name << " ";
        sep = ", ";
    }
    
    cout << endl << "The list now contains " << names.size() << " names: " << endl;
    
    /*Range based for loop*/
    std::string_view sep2 = "";
    for(string name : names)
    {
        cout << sep2 << name << " ";
        sep2 = ", ";
    }
    
    cout << endl << endl;
    
    /*Search for specific item*/
    if(names.find("B") != names.end())
    {
        cout << "Found B";
        cout << names.count("B") << endl;
    }
 #endif
    return 0;
}
