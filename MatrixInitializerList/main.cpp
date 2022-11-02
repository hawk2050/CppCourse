/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <ostream>
#include <array>
#include <cassert>

#include "matrix.h"


Matrix::Matrix()
{
    ++m_count; //Keep track of the number of instances of this class that have been instantiated.
    m_print_count = 0;
    //std::cout << "Creating instance " << m_count << std::endl;
    empty();
}

#if 0
Matrix::Matrix(const iListList& listlist)
{
    ++m_count;
    m_print_count = 0;
    init_cols = (unsigned)(listlist.begin())->size();
    init_rows = (unsigned)(listlist.size());
    
    cout << "row number = " << init_rows << '\n';
    cout << "col number = " << init_cols << '\n';
    
    assert(init_rows == Matrix::MAX_ROW);
    assert(init_cols == Matrix::MAX_COL);
    
/*Select each row, each row being an initializer_list itself*/ 
    unsigned row_index = 0, col_index = 0;
    for(auto& row : listlist)
    {
        
        /*Now, with the current row, iterate along the row, i.e
         * selecting each element from each column in that row
         * */
        col_index = 0;
        for(auto& cellval : row)
        {
            m_matrix[row_index][col_index] = cellval;
            ++col_index;
        }
        ++row_index;
    }
}
#else
Matrix::Matrix(const iListList& listlist)
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
#endif

Matrix::Matrix(int initial_value)
{
    /*Keep track of the number of instances of this class that have been instantiated. Have to
     * do this increment in every constructor type*/
    ++m_count;
    m_print_count = 0;
    //std::cout << "Creating with value " << initial_value << " instance " << m_count << std::endl;
    init(initial_value);
}

/*Copy constructor*/
Matrix::Matrix(const Matrix& matrix)
{
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

string Matrix::nameOf()
{
    string s;
    s = "Matrix";
    return s;
}

/*Assign values to each element of the fixed sized matrix*/
void Matrix::setElement(unsigned row, unsigned col, int value)
{
    /*Range checking is automatic with std::array type*/
    MatrixBoundsException arrayExcept;
    if(row >= MAX_ROW or col >=MAX_COL)
    {
        throw arrayExcept;
    }
    m_matrix[row][col] = value;
} 


void Matrix::init(int val)
{
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
        {
            m_matrix[j][k] = val;
        }
    }
}

/*Zero the fixed size matrix*/
void Matrix::empty()
{
    for(size_t j=0; j< MAX_ROW; j++)
    {
        for(size_t k=0; k< MAX_COL; k++)
        {
            m_matrix[j][k] = 0;
        }
    }
}

bool Matrix::operator==(const Matrix& othermatrix)
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

bool Matrix::operator!=(const Matrix& othermatrix)
{
    return (!(*this == othermatrix));
}

Matrix Matrix::operator+ (const Matrix& othermatrix) const
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
Matrix Matrix::operator- (const Matrix& othermatrix) const
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
Matrix& Matrix::operator+=(const Matrix& othermatrix)
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
int Matrix::operator[](unsigned index) const
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
int& Matrix::operator()(unsigned row, unsigned col) 
{
    return m_matrix.at(row).at(col);
}

const int& Matrix::operator()(unsigned row, unsigned col) const
{
    if(row > (MAX_ROW-1) or col > (MAX_COL-1))
    {
        cout << "Exceeds matrix dimension, setting to MAX_ROW, MAX_COL" << std::endl;
        row = MAX_ROW;
        col = MAX_COL;
    }
    return m_matrix.at(row).at(col);
}




ostream& operator<<(ostream& os, const Matrix& m)
{
    ++m.m_print_count;
    os << "[" ;
    for(size_t j=0; j< Matrix::MAX_ROW; j++)
    {
        os << "[";
        size_t k;
        for(k=0; k < Matrix::MAX_COL-1; k++)
        {
            os << m.m_matrix[j][k] << ", ";
        }
        os << m.m_matrix[j][k] << "]";
    }
    os << "]" << std::endl;
    //os << "printed " << m.m_print_count << " times" << std::endl << std::endl;
    return os;
}


int Matrix::m_count = 0;
int main()
{
    
	Matrix m1;
    
    m1(0,0) = 10;
    m1(0,1) = 20;
    
    Matrix m2{{2,3,4},{4,5,6}};
    cout << "m2 is : " << m2;
    
    /*Make the initializer list too large for the fixed size of the matrix*/
    Matrix m3{{2,3,4},{4,5,6},{6,7,8}};
    cout << "m3 is : " << m3;
    
    try
    {
        m1.setElement(3,4, 24); // Attempting to set an element outside the bounds of the array
    }
    catch(exception& e) //std library throws exceptions of this type
    {
        cout << "Exception: " << e.what() << endl;
    }
    
    cout << "m1 is : " << m1;
    
    cout << "m1 is of type: " << m1.nameOf() << endl;
    m1.trace();
    
   cout << "From C++ version " << __cplusplus << endl;
     
    
	return 0;
}
