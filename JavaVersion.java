/*
    Lina Kang
    CS4080 Section 3
    Professor Raheja
    October 20, 2023

    Java Version using a class called matrix and arrays and appropriate methods for the matrix operations

    The operator methods are used like so:
        Matrix m1 = new Matrix(3,3);
        Matrix m2 = new Matrix(3,3);

        Matrix resultMatrix = m1.add(m2);   // holds the resulting matrix of the addition of m1 and m2
*/


import java.util.Scanner;

class Matrix {
    
    public int row;
    public int col;
    public float[][] m;

    public Matrix(int r, int c)
    {
        row = r;
        col = c;
        m = new float[row][col];
    }
    // Addition Method
    public Matrix add (Matrix m2)
    {
        if(!(row == m2.row && col == m2.col))
        {
            System.out.println("Addition Invalid: Sizes do not match!\n");
            return null;
        }
        Matrix result = new Matrix(row, col);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] + m2.m[i][j];
          }
        }
      
        return result;
        
    }

    // Subtraction Method
    public Matrix sub (Matrix m2)
    {
        if(!(row == m2.row && col == m2.col))
        {
            System.out.println("Subtraction Invalid: Sizes do not match!\n");
            return null;
        }
        Matrix result = new Matrix(row, col);
    
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) {
                result.m[i][j] = m[i][j] - m2.m[i][j];
            }
        }
    
        return result;
  }
    // Multiply method
    public Matrix mult(Matrix m2)
    {
        if(!(col == m2.row))
        {
            System.out.println("Multiplication Invalid: Sizes do not match!\n");
            return null;
        }
        Matrix result = new Matrix(row, m2.col);
    
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < m2.col; j++)
            {
                for(int z = 0; z < col; z++)
                result.m[i][j] += m[i][z] * m2.m[z][j];
            }
        }
    
        return result;
    }
}

public class JavaVersion {

    public static void printMatrix(Matrix matrix) 
    {
        for (int i = 0; i < matrix.row; i++) {
            for (int j = 0; j < matrix.col; j++) {
            System.out.print(matrix.m[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
    public static Matrix matrixInput() {

        Scanner input = new Scanner(System.in);
        System.out.println();

        int row = 0;
        int col = 0;
        float temp = 0;
        
        int exceedsLimit = 1;
        while (exceedsLimit == 1) {
            // Ask the user to enter two matrices
            System.out.print("Enter how many rows for matrix (MAX: 100): ");
            row = input.nextInt();
            
            System.out.print("Enter how many columns for matrix (MAX: 100): ");
            col = input.nextInt();
            
        
            if (row > 100 || row > 100)
            System.out.println("Limit is 100 rows or columns. Please try again.");
            else
            exceedsLimit = 0;
        }
        System.out.println();
        
        Matrix matrix = new Matrix(row, col);
        
        // Ask the user to enter content for each matrices
        
        for (int i = 0; i < matrix.row; i++) {
            System.out.println("Enter row " + i + " for matrix 1: ");
    
            for (int j = 0; j < matrix.col; j++) {
                
                temp = input.nextFloat();
                matrix.m[i][j] = temp;

            
            }
            System.out.println();
        }
        
        // Print out the matrices
        
        System.out.println("Matrix: ");
        printMatrix(matrix);

        return matrix;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        Matrix m1 = matrixInput();
        Matrix m2 = matrixInput();
        System.out.println();

        Matrix addResult = null;
        Matrix subResult = null;
        Matrix multResult = null;

        int choice = 0;

        while (choice != 5) {
            System.out.println(" -- Menu -- ");
            System.out.println(" 1. Addition ");
            System.out.println(" 2. Subtraction ");
            System.out.println(" 3. Multiplication ");
            System.out.println(" 4. Enter Two NEW matrices ");
            System.out.println(" 5. Exit ");
            System.out.print(" Enter a number from menu: ");
            choice = input.nextInt();
            System.out.println();

            switch (choice) {
            case 1:
                if(addResult == null)
                    addResult = m1.add(m2);
                if(addResult != null)
                {
                    System.out.println("Final Matrix After Addition: ");
                    printMatrix(addResult);
                }
                break;
            case 2:
                if(subResult == null)
                    subResult = m1.sub(m2);
                if(subResult != null)
                {
                    System.out.println("Final Matrix After Subtraction: ");
                    printMatrix(subResult);
                }
                break;
            case 3:
                if(multResult == null)
                {
                    long start = System.nanoTime();
                    multResult = m1.mult(m2);
                    long finish = System.nanoTime();
                    System.out.println("Time calculated in milliseconds: ");
                    System.out.println((double)(finish-start)/1e9);
                }
                if(multResult != null)
                {
                    System.out.println("Current Matrix 1: ");
                    printMatrix(m1);
                    System.out.println("Current Matrix 2: ");
                    printMatrix(m2);
                    System.out.println("Final Matrix After Multiplication: ");
                    printMatrix(multResult);
                }
                break;
            case 4:
                addResult = null;
                subResult = null;
                multResult = null;
                m1 = matrixInput();
                m2 = matrixInput();
                break;
            case 5:
                choice = 5;
                break;
                default:
                System.out.println("Invalid Choice - Try Again ");
                break;
            }
        }
        input.close();
    }
}
