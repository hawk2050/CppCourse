#include <string>
#include <exception>
#include <initializer_list>

/*New use of the 'using' keyword to replace typedef*/
//template <class T>
//using iListList = std::initializer_list<std::initializer_list<T>>;

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
    
    /*To be overridden by derived classes, so mark this as a virtual function to 
     * ensure correct method resolution
     */
    virtual string nameOf() = 0;
    
};


/*Now turn the Matrix class into a templated class so we can
 * create matrix of things other than ints
 * A template is not code so should be placed in  header.
 * */
template <class T>
class Matrix : public Object
{
public:
/*No argument constructor*/
    Matrix();
    Matrix(const std::initializer_list<std::initializer_list<T>>& listlist);
    /*Single value argument for initialisation*/
    explicit Matrix(T initial_value);
    /*Copy constructor*/
    Matrix(const Matrix& matrix);
    ~Matrix()
    {
        --m_count;
    }
    string nameOf();
    
    [[deprecated("Use the () syntax instead")]]
    void setElement(unsigned row, unsigned col, T value = 0);
    void init(T val);
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
    T operator[](unsigned index) const;
    T& operator()(unsigned row, unsigned col) ;
    const T& operator()(unsigned row, unsigned col) const;
    
    friend ostream& operator<< <T>(ostream& os, const Matrix<T>& m); 
private:
    static const unsigned MAX_ROW = 2;
    static const unsigned MAX_COL = 3;
    static int m_count; //keep track of number of instances of this class
    
    unsigned init_rows, init_cols;
    array<array<T,MAX_COL>,MAX_ROW> m_matrix;
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};
