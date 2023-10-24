/*
    Lina Kang
    CS4080 Section 3
    Professor Raheja
    October 20, 2023

    C++ version that uses a pointer to a pointer as a private data in a class called
    matrix Add other appropriate member functions, like
        - constructors,
        - destructors and any other helper functions.
        - overloaded operator functions (for matrix operations) (+ for addition, -
    for subtraction and * for multiplication)
*/

#include <chrono>
#include <iostream>
using namespace std;

// Separate class Matrix made with overloaded operator functions
class Matrix
{
public:
  int row;
  int col;
  float **m;
  int init;
  Matrix(int r, int c);
  ~Matrix()
  {
    for (int i = 0; i < row; ++i)
    {
      delete[] m[i];
    }
    delete[] m;
  }
  Matrix *operator+(const Matrix &) const;
  Matrix *operator-(const Matrix &) const;
  Matrix *operator*(const Matrix &) const;
};

// define constructor
Matrix::Matrix(int r, int c)
{
  row = r;
  col = c;
  m = new float *[row];
  for (int i = 0; i < row; ++i)
  {
    m[i] = new float[col];
    for (int j = 0; j < col; j++)
    {
      m[i][j] = 0.0;
    }
  }
  init = 1;
}

void printMatrix(Matrix *matrix)
{
  for (int i = 0; i < (*matrix).row; i++)
  {
    for (int j = 0; j < (*matrix).col; j++)
    {
      cout << (*matrix).m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// define overloaded + (addition) operator
Matrix *Matrix::operator+(const Matrix &c) const
{
  if (!(row == c.row && col == c.col))
  {
    cout << "Addition Invalid: Sizes do not match!" << endl;
    return NULL;
  }
  Matrix *result = new Matrix(c.row, c.col);
  for (int i = 0; i < c.row; i++)
  {
    for (int j = 0; j < c.col; j++)
    {
      (*result).m[i][j] = m[i][j] + c.m[i][j];
    }
  }

  return result;
}
// define overloaded - (subtract) operator
Matrix *Matrix::operator-(const Matrix &c) const
{
  if (!(row == c.row && col == c.col))
  {
    cout << "Subtraction Invalid: Sizes do not match!" << endl;
    return NULL;
  }
  Matrix *result = new Matrix(c.row, c.col);

  for (int i = 0; i < c.row; i++)
  {
    for (int j = 0; j < c.col; j++)
    {
      (*result).m[i][j] = m[i][j] - c.m[i][j];
    }
  }

  return result;
}
// define overloaded * (multiply) operator
Matrix *Matrix::operator*(const Matrix &c) const
{
  if (!(col == c.row))
  {
    cout << "Multiplication Invalid: Sizes do not match!" << endl;
    return NULL;
  }
  Matrix *result = new Matrix(c.row, c.col);

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < c.col; j++)
    {
      for (int z = 0; z < col; z++)
        (*result).m[i][j] += m[i][z] * c.m[z][j];
    }
  }

  return result;
}

Matrix *matrixInput()
{

  int row = 0;
  int col = 0;

  int exceedsLimit = 1;
  while (exceedsLimit == 1)
  {
    // Ask the user to enter two matrices
    cout << "Enter how many rows for matrix (MAX: 100): ";
    cin >> row;
    cin.ignore(100, '\n');
    cout << "Enter how many columns for matrix (MAX: 100): ";
    cin >> col;
    cin.ignore(100, '\n');

    if (row > 100 || row > 100)
      cout << "Limit is 100 rows or columns. Please try again.\n";
    else
      exceedsLimit = 0;
  }

  Matrix *matrix = new Matrix(row, col);

  // Ask the user to enter content for each matrices

  for (int i = 0; i < (*matrix).row; i++)
  {
    cout << "Enter row " << i << " for matrix: \n";

    for (int j = 0; j < (*matrix).col; j++)
    {
      cin >> (*matrix).m[i][j];
      cin.ignore(1000, '\n');
    }
    cout << endl;
  }
  cout << endl;

  // Print out the matrices

  cout << "Matrix: \n";
  printMatrix(matrix);

  return matrix;
}

int main()
{
  Matrix *m1 = matrixInput();

  Matrix *m2 = matrixInput();

  Matrix *addResult = NULL;
  Matrix *subResult = NULL;
  Matrix *multResult = NULL;

  int choice = 0;

  while (choice != 5)
  {
    cout << " -- Menu -- \n";
    cout << " 1. Addition \n";
    cout << " 2. Subtraction \n";
    cout << " 3. Multiplication \n";
    cout << " 4. Enter Two NEW matrices \n";
    cout << " 5. Exit \n";
    cout << " Enter a number from menu: ";
    cin >> choice;
    cin.ignore(100, '\n');
    cout << "\n";
    switch (choice)
    {
    case 1:
      if (addResult == NULL)
        addResult = *m1 + *m2;
      if (addResult != NULL)
      {
        printf("Final Matrix After Addition: \n");
        printMatrix(addResult);
      }
      break;
    case 2:
      if (subResult == NULL)
        subResult = *m1 - *m2;
      if (subResult != NULL)
      {
        printf("Final Matrix After Subtraction: \n");
        printMatrix(subResult);
      }
      break;
    case 3:
      if (multResult == NULL)
      {
        auto t1 = chrono::high_resolution_clock::now();
        multResult = *m1 * *m2;
        auto t2 = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> ms_double = t2 - t1;
        cout << "Time calculated in milliseconds: " << ms_double.count()
             << "ms\n";
      }
      if (multResult != NULL)
      {
        printf("Current Matrix 1: \n");
        printMatrix(m1);
        printf("Current Matrix 2: \n");
        printMatrix(m2);
        printf("Final Matrix After Multiplication: \n");
        printMatrix(multResult);
      }
      break;
    case 4:
      free(m1);
      free(m2);
      if (addResult != NULL)
      {
        free(addResult);
        addResult = NULL;
      }
      if (subResult != NULL)
      {
        free(subResult);
        subResult = NULL;
      }
      if (multResult != NULL)
      {
        free(multResult);
        multResult = NULL;
      }
      m1 = matrixInput();
      m2 = matrixInput();
      break;
    case 5:
      choice = 5;
      free(m1);
      free(m2);
      if (addResult->init != 1)
        free(addResult);
      if (subResult->init != 1)
        free(subResult);
      if (multResult->init != 1)
        free(multResult);
      break;
    default:
      printf("Invalid Choice - Try Again \n");
      break;
    }
  }
}