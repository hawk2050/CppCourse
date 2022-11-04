#ifndef __DATECLASS_H__
#define __DATECLASS_H

#include <array>
#include <cstdint>

const uint16_t DAYS_IN_YEAR = 365;

const std::array<uint8_t,12> DaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

enum class Calendar { Gregorian, Julian, Chinese};

using day = uint32_t;
using month = uint32_t;
using year = uint32_t;

std::ostream& operator<<(std::ostream& os, const Calendar& m) ;

class Date
{
public:
    Date(day days, month months, year years);
    Date();
    
    ~Date()
    {
        
    }
    
    bool operator<(const Date& otherdate) const;
    day operator-(const Date& otherdate) const;
    /*Caculate a new date after adding days to the current date*/
    Date operator+(const uint32_t days) const;
    //Calendar getCalendar();
    
    friend std::ostream& operator<<(std::ostream& os, const Date& m);
    //friend std::ostream& operator<<(std::ostream& os, const Calendar& m) ;
private:
    
    day     m_day;
    month   m_month;
    year    m_year;
    Calendar m_calendar;
};

#endif

