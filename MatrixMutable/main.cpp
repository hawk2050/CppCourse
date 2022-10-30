/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>

const unsigned MAX_ROW = 2;
const unsigned MAX_COL = 3;

class Matrix
{
public:
    Matrix()
    {
        ++m_count;
        m_print_count = 0;
        std::cout << "Creating instance " << m_count << std::endl;
        empty();
    }
    
    /*Converting constructor*/
    explicit Matrix(int initial_value)
    {
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
    
    
    void print() const
    {
        ++m_print_count;
        std::cout << "[" ;
        for(size_t j=0; j< MAX_ROW; j++)
        {
            std::cout << "[";
            size_t k;
            for(k=0; k < MAX_COL-1; k++)
            {
                std::cout << m_matrix[j][k] << ", ";
            }
            std::cout << m_matrix[j][k] << "]";
        }
        std::cout << "]" << std::endl;
        std::cout << "printed " << m_print_count << " times" << std::endl << std::endl;
        
    }
    
    bool equal(const Matrix& m) const
    {
        bool result = true;
        for(size_t j=0; j< MAX_ROW; j++)
        {
            for(size_t k=0; k< MAX_COL; k++)
            {
                if (this->m_matrix[j][k] != m.m_matrix[j][k])
                {
                    result = false;
                    break;
                }
            }
        }
        return result;
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
    
    
    

    
private:
    static int m_count; //keep track of number of instances of this class
    int m_matrix[MAX_ROW][MAX_COL];
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};

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
    
    

	std::cout << "Matrix m1 is ";
	m1.print();
    m1.print();
    m1.print();
    m1.print();

	std::cout << "Matrix m2 is ";
	m2.print();
    
    std::cout << "Matrix sum is ";
    m3.print();
    
    bool isequal = m3.equal(m2);
    std::cout << "Matrix m3 is " << (isequal ? "equal": "not equal") << " to m2" << std::endl << std::endl;
    
    std::cout << "Matrix m4 is initialised to " << " ";
    m4.print();
    
    std::cout << "Matrix m5 is initialised to m4" << " ";
    m5.print();
    
    std::cout << "Matrix m6 is initialised to m4" << " ";
    m6.print();
    
    //std::cout << "Matrix ones is initialised to ";
    //ones.print();
    

	return 0;
}
