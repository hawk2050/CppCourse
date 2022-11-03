#include <iostream>
#include <thread>

void countup(int final)
{
    for(int counter = 0; counter < final; ++counter)
    {
        std::cout << "in thread " << std::this_thread::get_id() << " count: " << counter << '\n';
    }
    
}


int main()
{
    std::cout << "Mainline started\n";
    
    //Launch 2 threads
	std::thread t1{countup, 100};
    std::thread t2{countup, 100};
    
    std::cout << "Mainline waiting\n";
    
    t1.join();
    t2.join();
    
    std::cout << "Mainline finished\n";
	return 0;
}
