#include <string>
#include <exception>
#include <initializer_list>

using namespace std;

/*New use of the 'using' keyword to replace typedef*/
using iListList = std::initializer_list<std::initializer_list<int>>;

class Object
{
public:
    Object()
    {
    }
    void trace()
    {
        cout << "Here";
    }
    
    /*To be overriddeen by derived classes, so mark this as a virtual function to 
     * ensure correct method resolution
     */
    virtual string nameOf() = 0;
    
};




class Matrix : public Object
{
public:
    Matrix();
    /*Introduce a new constructor that takes an initializer_list, actually for a 2-D matrix
     * it will be an initializer_list of initializer_lists
     * */
    Matrix(const iListList& listlist);
    
    explicit Matrix(int initial_value);
    Matrix(const Matrix& matrix);
    ~Matrix()
    {
        --m_count;
    }
    string nameOf();
    void setElement(unsigned row, unsigned col, int value = 0);
    void init(int val);
    /*Zero the fixed size matrix*/
    void empty();
    
    /*Define the matrix exception as an inner class of Matrix, should be in the public section as it needs to
     * be available to the outside world*/
    class MatrixBoundsException : public exception
    {
    public:
        virtual const char* what() const noexcept
        {
            return "Array bounds exception" ;
        }
    };
    
    /*Overloading operators*/
    bool operator==(const Matrix& othermatrix);
    bool operator!=(const Matrix& othermatrix);
    Matrix operator+(const Matrix& othermatrix) const;
    Matrix operator-(const Matrix& othermatrix) const;
    Matrix& operator+=(const Matrix& othermatrix);
    int operator[](unsigned index) const;
    int& operator()(unsigned row, unsigned col) ;
    const int& operator()(unsigned row, unsigned col) const;
    
    friend ostream& operator<<(ostream& os, const Matrix& m); 
private:
    static const unsigned MAX_ROW = 2;
    static const unsigned MAX_COL = 3;
    static int m_count; //keep track of number of instances of this class
    
    unsigned init_rows, init_cols;
    
    /*Exception error codes*/
    //static const int ARRAY_BOUND_ERR = 6;
    
    array<array<int,MAX_COL>,MAX_ROW> m_matrix;
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};
