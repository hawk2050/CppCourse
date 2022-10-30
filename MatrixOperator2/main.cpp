/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>
#include <ostream>

class Matrix
{
public:
    Matrix()
    {
        ++m_count; //Keep track of the number of instances of this class that have been instantiated.
        m_print_count = 0;
        std::cout << "Creating instance " << m_count << std::endl;
        empty();
    }
    
    /*Converting constructor*/
    explicit Matrix(int initial_value)
    {
        /*Keep track of the number of instances of this class that have been instantiated. Have to
         * do this increment in every constructor type*/
        ++m_count;
        m_print_count = 0;
        std::cout << "Creating with value " << initial_value << " instance " << m_count << std::endl;
        init(initial_value);
    }
    
    /*Copy constructor*/
    Matrix(const Matrix& matrix)
    {
        ++m_count;
        m_print_count = 0;
        std::cout << "Creating via copy , instance " << m_count << std::endl;
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
        std::cout << "Destroying" << std::endl;
        /*Every time an object is destroyed decrement our counter so we know how many
         * we have left. At end of program execution this should be 0!
         */
        --m_count;
        std::cout << "Class instances = " << m_count << std::endl;
    }
    
    /*Assign values to each element of the fixed sized matrix*/
    void setElement(unsigned row, unsigned col, int value = 0)
    {
        /*Make sure we don't exceed the matrix dimensions*/
        if(row > (MAX_ROW-1) or col > (MAX_COL-1))
        {
            std::cout << "Exceeds matrix dimension" << std::endl;
            return;
        }
        m_matrix[row][col] = value;
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
    
    /*This externally defined function needs to be declared as a friend function within the class*/
   friend std::ostream& operator<<(std::ostream& os, const Matrix& m); 

    
private:
    static const unsigned MAX_ROW = 2;
    static const unsigned MAX_COL = 3;
    static int m_count; //keep track of number of instances of this class
    int m_matrix[MAX_ROW][MAX_COL];
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
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
    os << "printed " << m.m_print_count << " times" << std::endl << std::endl;
    return os;
}


int Matrix::m_count = 0;
int main()
{
    
	Matrix m1, m2;
    
    const Matrix m4(35); 
    
    Matrix m5{m4};
    
    Matrix m6 = m4;
    
    /*Non explicit call to Matrix constructor, won't work if constructor is marked as explicit*/
    //Matrix ones = 1;

	m1.empty();
	m2.empty();

	m1.setElement(0, 0, 10);
	m1.setElement(0, 1, 20);
	m1.setElement(0, 2, 30);
	m1.setElement(1, 0, 40);
	m1.setElement(1, 1, 50);
	m1.setElement(1, 2, 60);

	m2.setElement(0, 0, 30);
	m2.setElement(0, 1, 50);
	m2.setElement(0, 2, 70);
	m2.setElement(1, 0, 10);
	m2.setElement(1, 1, 60);
	m2.setElement(1, 2); //exercises the default argument for value
    
    Matrix m3 = m1+m2;
    Matrix m7 = m1-m2;
    
    
	std::cout << "Matrix m1 is " << m1 << std::endl;
    std::cout << "Matrix m1 is " << m1 << std::endl;
    std::cout << "Matrix m1 is " << m1 << std::endl;

	std::cout << "Matrix m2 is " << m2;
    
    std::cout << "Matrix sum is " << m3;
    
    std::cout << "Matrix m3 is " << (m3==m2 ? "equal": "not equal") << " to m2" << std::endl << std::endl;
    
    std::cout << "Matrix m3 is " << (m3!=m2 ? "not equal": "equal") << " to m2" << std::endl << std::endl;
    
    std::cout << "Matrix m4 is initialised to " << " " << m4;
    
    std::cout << "Matrix m5 is initialised to m4" << " " << m5;
    
    std::cout << "Matrix m6 is initialised to m4" << " " << m6;
    
    std::cout << "Matrix difference (m1-m2) is " << " " << m7;
    
    /*Exercise the in-place add and accumulate operator += */
    std::cout << "Add m1: "<< m1 << "to m3: " << m3 << "and store it back in m3 and we get: " ;
    m3 += m1;
    std::cout << m3 << std::endl;
    
    //std::cout << "Matrix ones is initialised to ";
    //ones.print();
    

	return 0;
}
