#include <iostream>
#include <cassert>
#include <set>

#include "dateclass.h"

Date::Date(day days, month months, year years):
    m_day(days),
    m_month(months),
    m_year(years),
    m_calendar(Calendar::Gregorian)
{
    assert(days <= 31);
    assert(months <= 12);
}

Date::Date():
    m_day(0),
    m_month(0),
    m_year(0)
{
    
}

/*Overload the subtraction operator for the Matrix class*/
day Date::operator-(const Date& otherdate) const
{
    //uint32_t result;
    day sum_month_lhs = 0;
    day sum_month_rhs = 0;
    
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

/*Need this if we want to use sets to create an ordered set
 * of dates
 * */
bool Date::operator<(const Date& otherdate) const
{
    bool result = false;
    if(this->m_year < otherdate.m_year)
    {
        return true;
    }
    
    if(this->m_year > otherdate.m_year)
    {
        return false;
    }
    
    /*If we get to here then the years are the same, so now compare
     * based on the months
     * */
     if(this->m_month < otherdate.m_month)
    {
        return true;
    }
    
    if(this->m_month > otherdate.m_month)
    {
        return false;
    }
    
    /*If we get to here then the months are the same, so now compare
     * based on the day
     * */
     if(this->m_day < otherdate.m_day)
    {
        return true;
    }
    
    if(this->m_day > otherdate.m_month)
    {
        return false;
    }
    
    return result;
     
}

Date Date::operator+(const uint32_t add_days) const
{
    Date temp;
    year years;
    month months;
    day days;
    day sum_month_lhs = 0;
    
    for(size_t j = 0; j < this->m_month; ++j)
    {
        sum_month_lhs += DaysInMonth[j];
    }
    
    uint32_t total_days_orig = this->m_year * DAYS_IN_YEAR + sum_month_lhs + this->m_day;
    uint32_t total_days_sum = total_days_orig + add_days;
    
    years = total_days_sum / DAYS_IN_YEAR;
    //std::cout << "year = " << year;
    //uint16_t days_diff = (total_days_sum - year * DAYS_IN_YEAR);
    day days_diff = (total_days_sum % DAYS_IN_YEAR);
    //std::cout << "days_diff = " << days_diff;
    
    day sum_month_days = 0;
    for(size_t j = 0; j < DaysInMonth.size(); ++j)
    {
        sum_month_days += DaysInMonth[j];
        if(sum_month_days >= days_diff)
        {
            months = j;
            break;
        }
    }
    
    days = sum_month_days -days_diff;
    temp.m_year = years;
    temp.m_month = months;
    temp.m_day = days;
    
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Date& m)
{
    os << "[" << m.m_day << "/" << m.m_month << "/" << m.m_year << "]" << "(" << m.m_calendar << ")\n" ;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Calendar& m)
{
    switch(m)
    {
        case Calendar::Gregorian:
            os << "Gregorian";
            break;
        case Calendar::Julian:
            os << "Julian";
            break;
        case Calendar::Chinese:
            os << "Chinese";
            break;
        default:
        os << "Unknown";
        
    }
    return os;
}


int main()
{
    const Date d1(23,6,2022);
    const Date d2(12,2,2023);
    
    std::set<Date> dates;
    
    dates.insert(d1);
    dates.insert(d2);
    
    std::cout << "Date difference between << " << d1 << " and " << d2 << " is : " << (d2 - d1) << "days\n";
    
    const Date d3(1,1,1999);
    const Date d4(14,9,1994);
    const Date d6(14,8,1994);
    const Date d7(15,8,1994);
    
    dates.insert(d3);
    dates.insert(d4);
    dates.insert(d6);
    dates.insert(d7);
    
    uint32_t days_diff = (d4-d3);
    std::cout << "Date difference between " << d3 << " and " << d4 << " is : " << days_diff << "days\n";
    
    Date d5;
    d5 = d3 + days_diff;
    std::cout << "Date d3 + " << days_diff << " days " << "is " << d5 << '\n';
    
    /*Using auto don't even have to declare a reverse_iterator!*/
    for(auto t_it = dates.rbegin(); t_it != dates.rend(); ++t_it)
    {
        std::cout << *t_it << " ";
    }
    
}
