#include "fibonacci.hpp"

Fibonacci::Fibonacci():
    m_last(0),
    m_last_last(0),
    m_current(0),
    m_state(0)
{
    
}

uint32_t Fibonacci::getNext()
{
    switch (m_state)
    {
        case 0:
        m_state++;
        
        break;
        
        case 1:
        m_state++;
        m_current = 1;
        m_last = m_current;
        
        break;
        
        default:
        m_state++;
        m_current = m_last_last + m_last;
        m_last_last = m_last;
        m_last = m_current;
        break;
        
        
        
    }
    
    
    return m_current;
}