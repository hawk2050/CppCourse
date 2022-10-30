#ifndef __FIBONACCI_HPP
#define __FIBONACCI_HPP

#include <stdint.h>

class Fibonacci
{
    public:
    Fibonacci();
    
    uint32_t getNext();
    
    private:
    uint32_t m_last;
    uint32_t m_last_last;
    uint32_t m_current;
    uint32_t m_state;
    
};


#endif