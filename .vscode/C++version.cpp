/*
C++ version that uses a pointer to a pointer as a private data in a class called matrix 
Add other appropriate member functions, like 
    - constructors, 
    - destructors and any other helper functions. 
    - overloaded operator functions (for matrix operations) (+ for addition, - for subtraction and * for multiplication)
*/

// 

#include <iostream>
using namespace std;

class Matrix {
    public:
        int row;
        int col;
        Matrix(int r, int c);
        ~Matrix()
        {

        }
        Matrix operator+(const Matrix&) const;
        Matrix operator-(const Matrix&) const;
        Matrix operator*(const Matrix&) const;

};

// define constructor
Matrix::Matrix( int r, int c )
{
      row = r; 
      col = c;
}

// define overloaded + (plus) operator
Matrix Matrix::operator+ (const Matrix& c) const
{
      Matrix result;
      result.real = (this->real + c.real);
      result.imag = (this->imag + c.imag);
      return result;
}
 
int main()
{

    return 0;
}