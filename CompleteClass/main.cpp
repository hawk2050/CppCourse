/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
 *  dotincomplete_new.cpp
 *      Stub for the class exercise
 */
 
 #include <iostream>

// Declare the class
class Dot
{
    public:
    
    Dot():
    m_x_coord(0),
    m_y_coord(0),
    m_on(false)
    {
        
    }
    
    void setOn()
    {
        m_on = true;
    }
    
    bool isItOn()
    {
        return m_on;
    }
    
    int getX()
    {
        return m_x_coord;
    }
    
    int getY()
    {
        return m_y_coord;
    }
    
    void position(int x, int y)
    {
        m_x_coord = x;
        m_y_coord = y;
    }
    
    private:
    int m_x_coord;
    int m_y_coord;
    bool m_on;

};

// Mainline --------------------------------
int main()
{
    Dot corner;

    corner.setOn();
    corner.position(5, 10);

    if (corner.isItOn())
        std::cout << "The Dot is now On\n";     // Should print

    // Should print "The Dot is at 5 10"
    std::cout << "The Dot is at " << corner.getX() << " " << corner.getY() << std::endl;

    return 0;
}

