/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <ostream>
#include <array>
#include <cassert>

using namespace std;
/*Need a forward declaration for the friend function which has to be defined before
 * the Matrix class is defined, which happens in the header, so must go before the header
 * */
template <class T>
class Matrix;

template <class T>
ostream& operator<<(ostream& os, const Matrix<T>& m)
{
    ++m.m_print_count;
    os << "[" ;
    for(size_t j=0; j< Matrix<T>::MAX_ROW; j++)
    {
        os << "[";
        size_t k;
        for(k=0; k < Matrix<T>::MAX_COL-1; k++)
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

template <class T>
Matrix<T>::Matrix()
{
    assert(m_count >= 0);
    ++m_count; //Keep track of the number of instances of this class that have been instantiated.
    m_print_count = 0;
    //std::cout << "Creating instance " << m_count << std::endl;
    empty();
}

template <class T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &listlist)
{
    ++m_count;
    m_print_count = 0;
    init_cols = (unsigned)(listlist.begin())->size();
    init_rows = (unsigned)(listlist.size());
    
    //cout << "row number = " << init_rows << '\n';
    //cout << "col number = " << init_cols << '\n';
    
    assert(init_rows == Matrix::MAX_ROW);
    assert(init_cols == Matrix::MAX_COL);
    
    /*Select each row, each row being an initializer_list itself*/ 
    unsigned row_index = 0;
    for(auto& row : listlist)
    {
        std::copy(row.begin(),row.end(),m_matrix[row_index++].begin());
    }
    
}

template <class T>
Matrix<T>::Matrix(T initial_value)
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
template <class T>
Matrix<T>::Matrix(const Matrix& matrix)
{
    assert(m_count >= 0);
    ++m_count;
    m_print_count = 0;
    //std::cout << "Creating via copy , instance " << m_count << std::endl;
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
        {
            this->m_matrix[j][k] = matrix.m_matrix[j][k];
        }
    }
    
}

template <class T>
string Matrix<T>::nameOf()
{
    string s;
    s = "Matrix";
    return s;
}

/*Assign values to each element of the fixed sized matrix*/
template <class T>
void Matrix<T>::setElement(unsigned row, unsigned col, T value)
{
    /*Range checking is automatic with std::array type*/
    MatrixBoundsException arrayExcept;
    if(row >= MAX_ROW or col >=MAX_COL)
    {
        throw arrayExcept;
    }
    m_matrix[row][col] = value;
} 

template <class T>
void Matrix<T>::init(T val)
{
    for(auto& row : m_matrix)
    {
        for(auto& cell : row)
        {
            cell = val;
        }
    }
}

/*Zero the fixed size matrix*/
template <class T>
void Matrix<T>::empty()
{
    for(auto& row : m_matrix)
    {
        for(auto& cell : row)
        {
            cell = 0;
        }
    }
}



template <class T>
bool Matrix<T>::operator==(const Matrix& othermatrix)
{
   bool result = true;
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
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

template <class T>
bool Matrix<T>::operator!=(const Matrix& othermatrix)
{
    return (!(*this == othermatrix));
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix& othermatrix) const
{
    Matrix result;
    
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
        {
            result.m_matrix[j][k] = this->m_matrix[j][k] + othermatrix.m_matrix[j][k];
        }
    }
    
    return result;
}

/*Overload the subtraction operator for the Matrix class*/
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& othermatrix) const
{
    Matrix result;
    
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
        {
            result.m_matrix[j][k] = this->m_matrix[j][k] - othermatrix.m_matrix[j][k];
        }
    }
    
    return result;
}

/*Overload the in-place operator += (Dyadic, or binary) */
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& othermatrix)
{
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
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
template <class T>
T Matrix<T>::operator[](unsigned index) const
{
    unsigned temp = 0;
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
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
template <class T>
T& Matrix<T>::operator()(unsigned row, unsigned col) 
{
    return m_matrix.at(row).at(col);
}

template <class T>
const T& Matrix<T>::operator()(unsigned row, unsigned col) const
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
template <class T>
int Matrix<T>::m_count = 0;
int main()
{
    
	Matrix<int> m1;
    //Matrix<double> m2;
    
    m1(0,0) = 10;
    m1(0,1) = 20;
    
    /*Digit separators*/
    Matrix m2{{2'500'547,3'567,460'977},{357'543,269'632,852'570}};
    cout << "m2 (large number matrix) is : " << m2;
    
    try
    {
        //m1.setElement(1,1, 24); // Attempting to set an element outside the bounds of the array
    }
    catch(exception& e) //std library throws exceptions of this type
    {
        cout << "Exception: " << e.what() << endl;
    }
    
    cout << "m1 (int matrix) is : " << m1;
    
    
    cout << "m1 is of type: " << m1.nameOf() << endl;
    m1.trace();
    
    //cout << "From C++ version " << __cplusplus << endl;
     
    
	return 0;
}
