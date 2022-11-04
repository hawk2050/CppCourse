#include <iostream>
#include <memory>
using namespace std;

/*Change this code to use smart pointers*/

int main()
{
    //int number;
    int count;
    
    // Ask them how many numbers they have
    cout << "How many numbers do you have?";
    cin >> count;
    
    /* Allocate an array of that size. This is a unique pointer
    only one can point at this bit of memory.
     * */
    unique_ptr<int[]> numbers(new int[count]);
    
    /*Shared pointer allows multiple pointers to be pointing
     * at the same bit of memory, and it will keep track of the
     * number of references to that memory, and only release
     * the memory when the number of references has dropped to 0
     * */
     std::shared_ptr<int[]> p1(new int[count]);
     /*Can make copies of shared pointers*/
     std::shared_ptr<int[]> p2 = p1;
    
    // Get all those numbers
    for (int i = 0; i < count; ++i)
    { 
        cout << "Please enter a number: ";
        cin >> numbers[i];
    }

    // Print those numbers to the screen
    for (int i = 0; i < count; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Must remember to release memory!
    //delete[] numbers;
    
    return 0;
}
