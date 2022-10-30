/*
 *	MatrixMain1.cpp
 *		Program to be completed by students.
 */
#include <iostream>

#define MAX_ROW 2
#define MAX_COL 3

class Matrix
{
public:
    Matrix()
    {
        std::cout << "Creating" << std::endl;
        empty();
    }
    
    Matrix(int initial_value)
    {
        std::cout << "Creating with value " << initial_value << std::endl;
        init(initial_value);
    }
    
    ~Matrix()
    {
        std::cout << "Destroying" << std::endl;
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
    
    
    void print()
    {
        std::cout << "[" ;
        for(size_t j=0; j< MAX_ROW; j++)
        {
            std::cout << "[";
            for(size_t k=0; k< MAX_COL; k++)
            {
                std::cout << m_matrix[j][k] << ", ";
            }
            std::cout << "]";
        }
        std::cout << "]" << std::endl;
        
    }
    
    bool equal(Matrix m)
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
    
    Matrix operator+ (Matrix othermatrix)
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
    
    int m_matrix[MAX_ROW][MAX_COL];
    
    

};


int main()
{
	Matrix m1, m2;
    
    Matrix m4(35);

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

	std::cout << "Matrix m2 is ";
	m2.print();
    
    std::cout << "Matrix sum is ";
    m3.print();
    
    std::cout << "Matrix m4 is initialised to ";
    m4.print();
    
    bool isequal = m3.equal(m2);
    std::cout << "Matrix m3 is " << (isequal ? "equal": "not equal") << " to m2" << std::endl;

	return 0;
}
