/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <ostream>
#include <array>
#include <cassert>

/*Actually, not recommended to do this with namespace std*/
using namespace std;
/*Need a forward declaration for the friend function which has to be defined before
 * the Matrix class is defined, which happens in the header, so must go before the header
 * */
template <class T, unsigned ROW, unsigned COL>
class Matrix;

template <class T, unsigned ROW, unsigned COL>
ostream& operator<<(ostream& os, const Matrix<T,ROW,COL>& m)
{
    ++m.m_print_count;
    os << "[" ;
    for(size_t j=0; j< m.MAX_ROW; j++)
    {
        os << "[";
        size_t k;
        for(k=0; k < m.MAX_COL-1; k++)
        {
            os << m.m_matrix[j][k] << ", ";
        }
        os << m.m_matrix[j][k] << "]";
    }
    os << "]" << std::endl;
    //os << "printed " << m.m_print_count << " times" << std::endl << std::endl;
    return os;
}

#include "matrix.h"

template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL>::Matrix():
    MAX_ROW(ROW),
    MAX_COL(COL)
{
    assert(m_count >= 0);
    ++m_count; //Keep track of the number of instances of this class that have been instantiated.
    m_print_count = 0;
    //std::cout << "Creating instance " << m_count << std::endl;
    empty();
}

template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL>::Matrix(const std::initializer_list<std::initializer_list<T>> &listlist):
    MAX_ROW(ROW),
    MAX_COL(COL)
{
    ++m_count;
    m_print_count = 0;
    init_cols = (unsigned)(listlist.begin())->size();
    init_rows = (unsigned)(listlist.size());
    
    //cout << "row number = " << init_rows << '\n';
    //cout << "col number = " << init_cols << '\n';
    
    assert(init_rows == ROW);
    assert(init_cols == COL);
    
    /*Select each row, each row being an initializer_list itself*/ 
    unsigned row_index = 0;
    for(auto& row : listlist)
    {
        /*copy destination is the start address of each row, which is the start of each std::array that 
        makes up each row.*/
        std::copy(row.begin(),row.end(),m_matrix[row_index++].begin());
    }
    
}

template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL>::Matrix(T initial_value):
    MAX_ROW(ROW),
    MAX_COL(COL)
{
    assert(m_count >= 0);
    /*Keep track of the number of instances of this class that have been instantiated. Have to
     * do this increment in every constructor type*/
    ++m_count;
    m_print_count = 0;
    //std::cout << "Creating with value " << initial_value << " instance " << m_count << std::endl;
    init(initial_value);
}

/*Copy constructor*/
template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL>::Matrix(const Matrix& matrix)
{
    assert(m_count >= 0);
    ++m_count;
    m_print_count = 0;
    //std::cout << "Creating via copy , instance " << m_count << std::endl;
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            this->m_matrix[j][k] = matrix.m_matrix[j][k];
        }
    }
    
}

template <class T, unsigned ROW, unsigned COL>
string Matrix<T,ROW,COL>::nameOf()
{
    string s;
    s = "Matrix";
    return s;
}

/*Assign values to each element of the fixed sized matrix*/
template <class T, unsigned ROW, unsigned COL>
void Matrix<T,ROW,COL>::setElement(unsigned row, unsigned col, T value)
{
    /*Range checking is automatic with std::array type*/
    MatrixBoundsException arrayExcept;
    if(row >= ROW or col >=COL)
    {
        throw arrayExcept;
    }
    m_matrix[row][col] = value;
} 

template <class T, unsigned ROW, unsigned COL>
void Matrix<T,ROW,COL>::init(T val)
{
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            m_matrix[j][k] = val;
        }
    }
}

/*Zero the fixed size matrix*/
template <class T, unsigned ROW, unsigned COL>
void Matrix<T,ROW,COL>::empty()
{
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            m_matrix[j][k] = 0;
        }
    }
}

template <class T, unsigned ROW, unsigned COL>
template <unsigned ROWB, unsigned COLB>
bool Matrix<T,ROW,COL>::operator==(const Matrix<T, ROWB, COLB>& othermatrix)
{
    bool result = true;
    if( (ROW != ROWB) || (COL !=COLB) )
    {
       return false;
    }
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            if (this->m_matrix[j][k] != othermatrix.m_matrix[j][k])
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

template <class T, unsigned ROW, unsigned COL>
bool Matrix<T,ROW,COL>::operator!=(const Matrix& othermatrix)
{
    return (!(*this == othermatrix));
}

template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL> Matrix<T,ROW,COL>::operator+ (const Matrix& othermatrix) const
{
    Matrix result;
    
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            result.m_matrix[j][k] = this->m_matrix[j][k] + othermatrix.m_matrix[j][k];
        }
    }
    
    return result;
}

/*Overload the subtraction operator for the Matrix class*/
template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL> Matrix<T,ROW,COL>::operator-(const Matrix& othermatrix) const
{
    Matrix result;
    
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            result.m_matrix[j][k] = this->m_matrix[j][k] - othermatrix.m_matrix[j][k];
        }
    }
    
    return result;
}

/*Overload the in-place operator += (Dyadic, or binary) */
template <class T, unsigned ROW, unsigned COL>
Matrix<T,ROW,COL>& Matrix<T,ROW,COL>::operator+=(const Matrix& othermatrix)
{
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            this->m_matrix[j][k] = this->m_matrix[j][k] + othermatrix.m_matrix[j][k];
        }
    }
    return *this;
}

/*Overload the monadic operator + */
/*TODO*/

/*Overload the operator [],
 * treating rows and columns as single long row*/
template <class T, unsigned ROW, unsigned COL>
T Matrix<T,ROW,COL>::operator[](unsigned index) const
{
    unsigned temp = 0;
    for(size_t j=0; j< ROW; j++)
    {
        for(size_t k=0; k< COL; k++)
        {
            
            if(temp++ == index)
            {
                return m_matrix[j][k];
            }
        }
    }
    
    return 0;
}


/*Useful for cleaner assignment of values to the matrix object. Returning a reference to the int element
 * to allow something to be assigned to it*/
template <class T, unsigned ROW, unsigned COL>
T& Matrix<T,ROW,COL>::operator()(unsigned row, unsigned col) 
{
    return m_matrix.at(row).at(col);
}

template <class T, unsigned ROW, unsigned COL>
const T& Matrix<T,ROW,COL>::operator()(unsigned row, unsigned col) const
{
    if(row > (MAX_ROW-1) or col > (MAX_COL-1))
    {
        cout << "Exceeds matrix dimension, setting to MAX_ROW, MAX_COL" << std::endl;
        row = MAX_ROW;
        col = MAX_COL;
    }
    return m_matrix.at(row).at(col);
}


/*Initialise static class variable*/
template <class T, unsigned ROW, unsigned COL>
int Matrix<T,ROW,COL>::m_count = 0;
int main()
{
	Matrix<int,2,3> m1;
    
    m1(0,0) = 10;
    m1(0,1) = 20;
    cout << "m1 (int matrix) is : " << m1;
    cout << "m1 is of type: " << m1.nameOf() << endl;
    m1.trace();
    
    Matrix<double,3,3> m2{{2.5,3.5,4.6},{4.2,5.3,6.4},{2.1,6.7,9.8}};
    cout << "m2 (double matrix) is : " << m2;
    
    try
    {
        m1.setElement(3,4, 24); // Attempting to set an element outside the bounds of the array
        m2.setElement(3,4,56.4);
    }
    catch(exception& e) //std library throws exceptions of this type
    {
        cout << "Exception: " << e.what() << endl;
    }
    
    
    
    //cout << "From C++ version " << __cplusplus << endl;
     
    
	return 0;
}
