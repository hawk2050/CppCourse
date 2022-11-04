/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<string> names;
    set<string>::iterator it;
    set<string>::reverse_iterator r_it;
    string myname;
    const string term = "quit";
    
    while(true)
    {
        cout << "Please enter a name (quit or Enter to end): ";
        getline(cin,myname);
        if(myname == term or myname=="" )
        {
            break;
        }
        
        names.insert(myname);
    }
    
    cout << "The " << names.size() << " entered were: ";
    //cout << "String List capacity is: " << names.capacity() << '\n';
    cout << "String List max size is: " << names.max_size() << '\n';
    
    /*Iterator based for loop*/
    for(it = names.begin(); it != names.end(); ++it)
    {
        cout << *it << " ";
    }
    
    cout << endl << endl;
    
     /*Reverse Iterator based for loop*/
    for(r_it = names.rbegin(); r_it != names.rend(); ++r_it)
    {
        cout << *r_it << " ";
    }
    
    cout << endl << endl;
    
    /*Using auto don't even have to declare a reverse_iterator!*/
    for(auto t_it = names.rbegin(); t_it != names.rend(); ++t_it)
    {
        cout << *t_it << " ";
    }
 
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
 
    return 0;
}
