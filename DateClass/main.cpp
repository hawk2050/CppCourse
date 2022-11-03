#include <iostream>
#include <cassert>

#include "dateclass.h"

Date::Date(uint16_t day, uint16_t month, uint16_t year):
    m_day(day),
    m_month(month),
    m_year(year)
{
    assert(day <= 31);
    assert(month <= 12);
}

Date::Date():
    m_day(0),
    m_month(0),
    m_year(0)
{
    
}

void Date::setDay(uint16_t day)
{
    
}

uint16_t Date::getDay()
{
    return m_day;
}

uint16_t Date::getMonth()
{
    return m_month;
}

uint16_t Date::getYear()
{
    return m_year;
}

/*Overload the subtraction operator for the Matrix class*/
uint32_t Date::operator-(const Date& otherdate) const
{
    //uint32_t result;
    uint16_t sum_month_lhs = 0;
    uint16_t sum_month_rhs = 0;
    
    for(size_t j = 0; j < this->m_month; ++j)
    {
        sum_month_lhs += DaysInMonth[j];
    }
    for(size_t j = 0; j < otherdate.m_month; ++j)
    {
        sum_month_rhs += DaysInMonth[j];
    }
    
    //std::cout << "sum_month: " << sum_month_rhs << '\n';
    
    
    uint32_t total_days_lhs = this->m_year * DAYS_IN_YEAR + sum_month_lhs + this->m_day;
    uint32_t total_days_rhs = otherdate.m_year * DAYS_IN_YEAR + sum_month_rhs + otherdate.m_day;
       
    
    return (total_days_lhs - total_days_rhs);
}

Date Date::operator+(const uint32_t days) const
{
    Date temp;
    uint16_t year;
    uint16_t month;
    uint16_t day;
    uint16_t sum_month_lhs = 0;
    
    for(size_t j = 0; j < this->m_month; ++j)
    {
        sum_month_lhs += DaysInMonth[j];
    }
    
    uint32_t total_days_orig = this->m_year * DAYS_IN_YEAR + sum_month_lhs + this->m_day;
    uint32_t total_days_sum = total_days_orig + days;
    
    year = total_days_sum / DAYS_IN_YEAR;
    //std::cout << "year = " << year;
    //uint16_t days_diff = (total_days_sum - year * DAYS_IN_YEAR);
    uint16_t days_diff = total_days_sum % DAYS_IN_YEAR;
    //std::cout << "days_diff = " << days_diff;
    
    uint16_t sum_month_days = 0;
    for(size_t j = 0; j < DaysInMonth.size(); ++j)
    {
        sum_month_days += DaysInMonth[j];
        if(sum_month_days >= days_diff)
        {
            month = j;
            break;
        }
    }
    
    day = sum_month_days -days_diff;
    temp.m_year = year;
    temp.m_month = month;
    temp.m_day = day;
    
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Date& m)
{
    os << "[" << m.m_day << "/" << m.m_month << "/" << m.m_year << "]" ;
    return os;
}


int main()
{
    const Date d1(23,6,2022);
    const Date d2(23,6,2023);
    
    std::cout << "Date difference between << " << d1 << " and " << d2 << " is : " << (d2 - d1) << "days\n";
    
    const Date d3(1,1,1994);
    const Date d4(14,9,1994);
    uint32_t days_diff = (d4-d3);
    std::cout << "Date difference between " << d3 << " and " << d4 << " is : " << days_diff << "days\n";
    
    Date d5;
    d5 = d3 + days_diff;
    std::cout << "Date d3 + " << days_diff << " days " << "is " << d5 << '\n';
    
}
