/*
    Lina Kang
    CS4080 Section 3
    Professor Raheja
    October 20, 2023

    Part 1 of Programming Project 1
    C version that uses a pointer to a pointer (**p) 
    that is allocated memory using new or malloc to create the 2D matrices. 
    Provide 3 functions, one for addition, subtraction and multiplication respectively, 
    that take in the two matrices and return the result back 
    (as a new matrix which is also declared as a pointer to a pointer) 

*/


#include <stdio.h>
#include <stdlib.h>
#define LAST 10

int row1 = 0;
int col1 = 0;

int row2 = 0;
int col2 = 0;

void printMatrix(float ***matrix, int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            printf("%.1f ", (*matrix)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixInput(float ***matrix1, float ***matrix2)
{
    int exceedsLimit = 1;
    while(exceedsLimit == 1)
    {
        // Ask the user to enter two matrices
        printf("Enter how many rows for matrix 1 (MAX: 100): ");
        scanf("%d", &row1);
        printf("Enter how many columns for matrix 1 (MAX: 100): ");
        scanf("%d", &col1);
        printf("Enter how many rows for matrix 2 (MAX: 100): ");
        scanf("%d", &row2);
        printf("Enter how many columns for matrix 2 (MAX: 100): ");
        scanf("%d", &col2);

        if(row1 > 100 || row2 > 100 || col1 > 100 || col2 > 100)
            printf("Limit is 100 rows or columns. Please try again.\n");
        else
            exceedsLimit = 0;
    }


    // initialize a dynamic stack 2D array

    *matrix1 = malloc(row1 * sizeof(float*));
    *matrix2 = malloc(row2 * sizeof(float*));
    for(int i = 0; i < row1; i++)
        (*matrix1)[i] = malloc(col1 * sizeof(float));
    for(int i = 0; i < row2; i++)
        (*matrix2)[i] = malloc(col2 * sizeof(float));

    // Ask the user to enter content for each matrices
    for (int i = 0; i < row1; i++)
    {
        printf("Enter row %d for matrix 2:", i);
        printf("\n");
        for (int j = 0; j < col1; j++)
        {
            scanf("%f", &((*matrix1)[i][j]));
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < row2; i++)
    {
        printf("Enter row %d for matrix 2:", i);
        printf("\n");
        for (int j = 0; j < col2; j++)
        {
            scanf("%f", &((*matrix2)[i][j]));
        }
        printf("\n");
    }
    printf("\n");

    // Print out the matrices

    printf("Current Matrix 1: \n");
    printMatrix(&(*matrix1), row1, col1);
    printf("Current Matrix 2: \n");
    printMatrix(&(*matrix2), row2, col2);

    // for (int i = 0; i < row1; i++) {
    //     for (int j = 0; j < col1; j++)
    //     {
    //         printf("%.1f ", (*matrix1)[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < row2; i++) {
    //     for (int j = 0; j < col2; j++)
    //     {
    //         printf("%.1f ", (*matrix2)[i][j]);
    //     }
    //     printf("\n");
    // }

}

float** addition(float*** matrix1, float*** matrix2)
{
    
    // check size difference
    if(!(row1 == row2 && col1 == col2))
    {
        printf("Addition Invalid: Sizes do not match!\n\n");
        return NULL;
    }
    else
    {
        float **mFinal = malloc(row1 * sizeof(float*));
        for(int i = 0; i < row1; i++)
        {
            (mFinal)[i] = malloc(col1 * sizeof(float));
            for(int j = 0; j < col1; j++)
            {
                (mFinal)[i][j] = 0;
            }
        }
            
        //printMatrix(&mFinal, row1, col1);
        printf("Current Matrix 1: \n");
        printMatrix(&(*matrix1), row1, col1);
        printf("Current Matrix 2: \n");
        printMatrix(&(*matrix2), row2, col2);

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                printf("Adding matrices: %.1f + %.1f \n", (*matrix1)[i][j], (*matrix2)[i][j]);
                (mFinal)[i][j] = (*matrix1)[i][j] + (*matrix2)[i][j];
            }
        }
        printf("\n");
        printf("Final Matrix After Addition: \n");
        printMatrix(&mFinal, row1, col1);
        return mFinal;
    }
}

float** subtract(float*** matrix1, float*** matrix2)
{
    
    // check size difference
    if(!(row1 == row2 && col1 == col2))
    {
        printf("Subtraction Invalid: Sizes do not match!\n\n");
        return NULL;
    }
    else
    {
        float **mFinal = malloc(row1 * sizeof(float*));
        for(int i = 0; i < row1; i++)
        {
            (mFinal)[i] = malloc(col1 * sizeof(float));
            for(int j = 0; j < col1; j++)
            {
                (mFinal)[i][j] = 0;
            }
        }
            
        //printMatrix(&mFinal, row1, col1);
        printf("Current Matrix 1: \n");
        printMatrix(&(*matrix1), row1, col1);
        printf("Current Matrix 2: \n");
        printMatrix(&(*matrix2), row2, col2);

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                printf("Subtracting matrices: %.1f - %.1f \n", (*matrix1)[i][j], (*matrix2)[i][j]);
                (mFinal)[i][j] = (*matrix1)[i][j] - (*matrix2)[i][j];
            }
        }
        printf("\n");
        printf("Final Matrix After Subtraction: \n");
        printMatrix(&mFinal, row1, col1);
        return mFinal;
    }
}

float** multiply(float*** matrix1, float*** matrix2)
{
    
    // check size difference
    if(!(col1 == row2))
    {
        printf("Multiplication Invalid: Amount of columns in matrix 1 must equal amount of rows in matrix 2!\n\n");
        return NULL;
    }
    else
    {
        float **mFinal = malloc(row1 * sizeof(float*));
        for(int i = 0; i < row1; i++)
        {
            mFinal[i] = malloc(col2 * sizeof(float));
            for(int j = 0; j < col2; j++)
            {
                (mFinal)[i][j] = 0;
            }
        }

        printf("Current Matrix 1: \n");
        printMatrix(&(*matrix1), row1, col1);
        printf("Current Matrix 2: \n");
        printMatrix(&(*matrix2), row2, col2);

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for(int z = 0; z < col1; z++)
                    mFinal[i][j] += (*matrix1)[i][z] * (*matrix2)[z][j];
            }
        }
        printf("Final Matrix After Multiplication: \n");
        printMatrix(&mFinal, row1, col2);
        return mFinal;
    }
}

int main()
{
    float** matrix1;
    float** matrix2;

    float** addResult = NULL;
    float** subResult = NULL;
    float** multResult = NULL;

    matrixInput(&matrix1, &matrix2);
    // Show menu
    // - add matrix
    // - subtract matrix
    // - multiply matrix
    // - enter two new matrices
    // - exit menu

    printf("\n");

    int choice = 0;

    while(choice != 5)
    {
        printf(" -- Menu -- \n");
        printf(" 1. Addition \n");
        printf(" 2. Subtraction \n");
        printf(" 3. Multiplication \n");
        printf(" 4. Enter Two NEW matrices \n");
        printf(" 5. Exit \n");
        printf(" Enter a number from menu: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                if(addResult == NULL)
                    addResult = addition(&matrix1, &matrix2);
                else
                {
                    printf("Final Matrix After Addition: \n");
                    printMatrix(&addResult, row1, col1);
                }
                    
                break;
            case 2:
                if(subResult == NULL)
                    subResult = subtract(&matrix1, &matrix2);
                else
                {
                    printf("Final Matrix After Subtraction: \n");
                    printMatrix(&subResult, row1, col1);
                }
                break;
            case 3:
                if(multResult == NULL)
                    multResult = multiply(&matrix1, &matrix2);
                else
                {
                    printf("Final Matrix After Multiplication: \n");
                    printMatrix(&multResult, row1, col2);
                }
                break;
            case 4:
                free(matrix1);
                free(matrix2);
                free(addResult);
                free(subResult);
                free(multResult);
                addResult = NULL;
                subResult = NULL;
                multResult = NULL;
                matrixInput(&matrix1, &matrix2);
                break;
            case 5:
                choice = 5;
                free(matrix1);
                free(matrix2);
                free(addResult);
                free(subResult);
                free(multResult);
                break;
            default:
                printf("Invalid Choice - Try Again \n");
                break;
        }

    }




    // result of every operation is printed out after the operation is chosen

    // int row = 3;
    // int column = 3;

    // for (int i = 0; i < row * column; i++)
    //     array[i] = i + 1;

    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < column; j++)
    //     {
    //         printf("%d ", array[i * column + j]);
    //     }
    //     printf("\n");
    // }

    free(matrix1);
    free(matrix2);
}
