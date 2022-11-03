#ifndef __DATECLASS_H__
#define __DATECLASS_H

#include <array>
#include <cstdint>

const uint16_t DAYS_IN_YEAR = 365;

const std::array<uint8_t,12> DaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
public:
    Date(uint16_t day, uint16_t month, uint16_t year);
    Date();
    
    ~Date()
    {
        
    }
    
    uint16_t getDay();
    uint16_t getMonth();
    uint16_t getYear();
    
    void setDay(uint16_t);
    void setMonth(uint16_t);
    void setYear(uint16_t);
    
    uint32_t operator-(const Date& otherdate) const;
    /*Caculate a new date after adding days to the current date*/
    Date operator+(const uint32_t days) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Date& m); 
private:
    
    uint16_t     m_day;
    uint16_t     m_month;
    uint16_t    m_year;
};

#endif

