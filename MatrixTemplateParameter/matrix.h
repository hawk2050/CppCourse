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
template <class T, unsigned ROW, unsigned COL>
class Matrix : public Object
{
public:
/*No argument constructor*/
    Matrix();
    /*Constructor that takes an initializer_list*/
    Matrix(const std::initializer_list<std::initializer_list<T>>& listlist);
    //Matrix(const iListList& listlist);
    /*Single value argument for initialisation*/
    explicit Matrix(T initial_value);
    /*Copy constructor*/
    Matrix(const Matrix& matrix);
    ~Matrix()
    {
        --m_count;
    }
    string nameOf();
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
    template <unsigned ROWB, unsigned COLB>
    bool operator==(const Matrix<T,ROWB, COLB>& othermatrix);
    
    bool operator!=(const Matrix& othermatrix);
    Matrix operator+(const Matrix& othermatrix) const;
    Matrix operator-(const Matrix& othermatrix) const;
    Matrix& operator+=(const Matrix& othermatrix);
    T operator[](unsigned index) const;
    T& operator()(unsigned row, unsigned col) ;
    const T& operator()(unsigned row, unsigned col) const;
    
    friend ostream& operator<< <T,ROW,COL>(ostream& os, const Matrix<T,ROW,COL>& m); 
private:
    const unsigned MAX_ROW;
    const unsigned MAX_COL;
    static int m_count; //keep track of number of instances of this class
    
    unsigned init_rows, init_cols;
    array<array<T,COL>,ROW> m_matrix;
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};
