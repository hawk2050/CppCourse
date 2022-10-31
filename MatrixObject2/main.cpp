/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <ostream>
#include <fstream>
#include <array>
#include "matrix.h"

#if 0
Matrix::Matrix()
{
    ++m_count; //Keep track of the number of instances of this class that have been instantiated.
    m_print_count = 0;
    //std::cout << "Creating instance " << m_count << std::endl;
    empty();
}

explicit Matrix::Matrix(int initial_value)
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
#endif

class Matrix : public Object
{
public:
    Matrix()
    {
        ++m_count; //Keep track of the number of instances of this class that have been instantiated.
        m_print_count = 0;
        //std::cout << "Creating instance " << m_count << std::endl;
        empty();
    }
    
    /*Converting constructor*/
    explicit Matrix(int initial_value)
    {
        /*Keep track of the number of instances of this class that have been instantiated. Have to
         * do this increment in every constructor type*/
        ++m_count;
        m_print_count = 0;
        //std::cout << "Creating with value " << initial_value << " instance " << m_count << std::endl;
        init(initial_value);
    }
    
    /*Copy constructor*/
    Matrix(const Matrix& matrix)
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
    
    ~Matrix()
    {
        //std::cout << "Destroying" << std::endl;
        /*Every time an object is destroyed decrement our counter so we know how many
         * we have left. At end of program execution this should be 0!
         */
        --m_count;
        //std::cout << "Class instances = " << m_count << std::endl;
    }
    
    string nameOf()
    {
        string s;
        s = "Matrix";
        return s;
    }
    
    /*Assign values to each element of the fixed sized matrix*/
    void setElement(unsigned row, unsigned col, int value = 0)
    {
        /*Range checking is automatic with std::array type*/
        m_matrix.at(row).at(col) = value;
    } 
    
    
    void init(int val)
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
    void empty()
    {
        for(size_t j=0; j< MAX_ROW; j++)
        {
            for(size_t k=0; k< MAX_COL; k++)
            {
                m_matrix[j][k] = 0;
            }
        }
    }
    
    bool operator==(const Matrix& othermatrix)
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
    
    bool operator!=(const Matrix& othermatrix)
    {
        return (!(*this == othermatrix));
    }
    
    Matrix operator+ (const Matrix& othermatrix) const
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
    Matrix operator- (const Matrix& othermatrix) const
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
    Matrix& operator+=(const Matrix& othermatrix)
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
    int operator[](unsigned index) const
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
    
    
    /*Useful for cleaner assignment of values to the matrix object*/
    int& operator()(unsigned row, unsigned col) 
    {
        return m_matrix.at(row).at(col);
    }
    
    const int& operator()(unsigned row, unsigned col) const
    {
        if(row > (MAX_ROW-1) or col > (MAX_COL-1))
        {
            cout << "Exceeds matrix dimension, setting to MAX_ROW, MAX_COL" << std::endl;
            row = MAX_ROW;
            col = MAX_COL;
        }
        return m_matrix.at(row).at(col);
    }
    
    
    /*This externally defined function needs to be declared as a friend function within the class*/
   friend ostream& operator<<(ostream& os, const Matrix& m); 

    
private:
    static const unsigned MAX_ROW = 2;
    static const unsigned MAX_COL = 3;
    static int m_count; //keep track of number of instances of this class
    array<array<int,MAX_COL>,MAX_ROW> m_matrix;
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};

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
    
    cout << "m1 is of type: " << m1.nameOf() << endl;
    m1.trace();
    
    Object o;
    cout << "o is type: " << o.nameOf() << endl;
    o.trace();
    cout << endl;
    
    #if 0
    Object*p;
    p = &o;
    cout << p->nameOf() << endl;
    p = &m1;
    cout << p->nameOf() << endl;
    #endif
   
    
  
	return 0;
}
