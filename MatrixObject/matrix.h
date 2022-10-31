#include <string>

using namespace std;

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
    
    string nameOf()
    {
        string s;
        s = "Object";
        return s;
    }
};

#if 0
class Matrix : public Object
{
public:
    Matrix();
    
    explicit Matrix(int initial_value);
    Matrix(const Matrix& matrix);
    string nameOf();
    void setElement(unsigned row, unsigned col, int value = 0);
    void init(int val);
    /*Zero the fixed size matrix*/
    void empty();
    
    bool operator==(const Matrix& othermatrix);
    bool operator!=(const Matrix& othermatrix);
    Matrix operator+ (const Matrix& othermatrix) const;
    Matrix operator- (const Matrix& othermatrix) const;
    Matrix& operator+=(const Matrix& othermatrix);
    int operator[](unsigned index) const;
    int& operator()(unsigned row, unsigned col) ;
    const int& operator()(unsigned row, unsigned col) const;
    
    friend ostream& operator<<(ostream& os, const Matrix& m); 
private:
    static const unsigned MAX_ROW = 2;
    static const unsigned MAX_COL = 3;
    static int m_count; //keep track of number of instances of this class
    array<array<int,MAX_COL>,MAX_ROW> m_matrix;
    mutable unsigned m_print_count; //this can be updated even for const Matrix objects
    
};
#endif