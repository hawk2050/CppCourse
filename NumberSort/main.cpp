#include <iostream>
#include <algorithm>

int main()
{
    std::array<int,10> m = {12, 42, 37, 49, 52, 60, 27, 68, 19, 210};
    
    /*Ascending sort*/
    std::sort(std::begin(m), std::end(m));
    
    std::string_view sep = "";
    for(auto val : m)
    {
        std::cout << sep << val;
        sep = ", ";
    }
    
    std::cout << std::endl;
    
     /*Descending sort*/
    std::cout << "Now sort in reverse" << std::endl;
    std::sort(std::rbegin(m), std::rend(m));
    
    sep = "";
    for(auto val : m)
    {
        std::cout << sep << val;
        sep = ", ";
    }
    
    /*Sort using a passed in Lambda comparator function*/
    std::sort(std::begin(m), std::end(m), [](int f, int s) -> bool {return f<s;});
    
    std::cout << std::endl;
    std::cout << "Now sort with lambda function (f < s)" << std::endl;
    
    sep = "";
    for(auto val : m)
    {
        std::cout << sep << val;
        sep = ", ";
    }
}
