
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name: Lawrence Wong
 * SBU ID: 116408194
 */

#include "matrix.h"
#include <stdio.h>
// #include "sparse_helpingfunction.c"
// #include "MuliplicationPrint.c" // parametes should be (int m, int S[3][m])

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

/*----------------------------------------------------
  1. Sparse Matrix
----------------------------------------------------*/
int SparseMatrix(int D[2], int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])])
{

    int rows = D[0];
    int cols = D[1];
    int m = max(rows, cols);

    int nonZeroCount = 0;

    // Count non zero numbers
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(*(*(M + i) + j) != 0){
                nonZeroCount++;
            }
        }
    }

    // Checks for if it is a sparse matrix depending on how many non zero numbers
    if(nonZeroCount > m){
        return -1;
    }

    // Fills up the S matrix for the rows and columns
    int k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(*(*(M + i) + j) != 0){
                *(*(S + 0) + k) = i;
                *(*(S + 1) + k) = j;
                *(*(S + 2) + k) = *(*(M + i) + j);
                k++;
            }
        }
    }

    // Fill remaining columns with 0
    for(int col = k; col < m; col++){
        *(*(S + 0) + col) = 0;
        *(*(S + 1) + col) = 0;
        *(*(S + 2) + col) = 0;
    }
    // print_sparse_matrix(m, S);
    return nonZeroCount;
}


/*----------------------------------------------------
  2. Hadamard Product
----------------------------------------------------*/
int HadamardProduct(const int D[6],
                    const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]],
                    int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    // Determine overlap size
    int r = (mRows < nRows) ? mRows : nRows;
    int c = (mCols < nCols) ? mCols : nCols;

    // Initialize set A's size with 0s
    for(int i = 0; i < aRows; i++){
        for(int j = 0; j < aCols; j++){
            *(*(A + i) + j) = 0;
        }
    }

    // Fill A with overlapping multiplication using pointer arithmetic
    for(int i = 0; i < r && i < aRows; i++){
        for(int j = 0; j < c && j < aCols; j++){
            *(*(A + i) + j) = *(*(M + i) + j) * *(*(N + i) + j);    
        }
    }

    // print_matrix("A", *A, aRows, aCols);

    // When M and N same size
    if(mRows == nRows && mCols == nCols){
        if(aRows == r && aCols == c)
            return 1;   // Perfect fit
        else if(aRows >= r && aCols >= c)
            return 2;   // Oversized but fits
        else
            return -3;  // Not enough space
    }
    // When M and N different size
    else{
        if(aRows >= r && aCols >= c)
            return -1;  // Fits intersection result
        else
            return -2;  // Partial fit only
    }
}


/*----------------------------------------------------
  3. Matrix Multiplication
----------------------------------------------------*/
int Multiplication(const int D[6],
                   const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]],
                   int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    // Initialize set A's size with 0s
    for(int i = 0; i < aRows; i++){
        for(int j = 0; j < aCols; j++){
            *(*(A + i) + j) = 0;
        }
    }

    // Checks if the sizes are the compatible or not for matrix multiplication
    int compatible = (mCols == nRows);

    // Inner dimension
    int inner = compatible ? mCols : (mCols < nRows ? mCols : nRows);

    // Result dimensions
    int r = mRows;
    int c = nCols;

    // Multiply the matrices only for the dimensions of A
    for(int i = 0; i < r && i < aRows; i++){
        for(int j = 0; j < c && j < aCols; j++){
            int sum = 0;
            for(int k = 0; k < inner; k++){
                sum += (*(*(M + i) + k)) * (*(*(N + k) + j));
            }
            *(*(A + i) + j) = sum;
        }
    }

    // print_matrix("A", *A, aRows, aCols);

    // Returns the cases
    if(compatible){
        if(aRows == r && aCols == c)
            return 1;   // Exact fit
        else if(aRows >= r && aCols >= c)
            return 2;   // Oversized but fits
        else
            return -3;  // Partial result only
    }
    else{
        if(aRows >= r && aCols >= c)
            return -1;  // Fits multiplication result
        else
            return -2;  // Partial fit
    }
}


/*----------------------------------------------------
  4. Diagonal Sum
----------------------------------------------------*/
int DiagonalSum(const int D[4],
                const int A[D[0]][D[1]],
                int DS[D[2]][D[3]])
{

    int rows = D[0];
    int cols = D[1];

    int dsRows = D[2];
    int dsCols = D[3];

    // Initialize DS to 0
    int *dsPtr = (int *)DS;
    for(int i = 0; i < dsRows * dsCols; i++)
        *(dsPtr + i) = 0;

    // Required size
    int reqRows = rows + 2;
    int reqCols = (cols > 2) ? cols : 2;

    // Handles the diagonal
    int mainDiag = 0;
    for(int i = 0; i < rows && i < cols; i++)
        mainDiag += *(*(A + i) + i);
    if(dsRows > 0 && dsCols > 0)
        *(*(DS + 0) + 0) = mainDiag;

    // Handles the anti-diagonal
    if(rows == cols){
        int antiDiag = 0;
        for(int i = 0; i < rows; i++)
            antiDiag += *(*(A + i) + (cols - 1 - i));

        if(dsRows > 0 && dsCols > 1)
            *(*(DS + 0) + 1) = antiDiag;
    }

    // Handles the sums of columns
    for(int j = 0; j < cols; j++){
        int colSum = 0;
        for(int i = 0; i < rows; i++)
            colSum += *(*(A + i) + j);

        if(dsRows > 1 && j < dsCols)
            *(*(DS + 1) + j) = colSum;
    }

    // Handles the sums of rows
    for(int i = 0; i < rows; i++){
        int rowSum = 0;
        for(int j = 0; j < cols; j++)
            rowSum += *(*(A + i) + j);

        if((i + 2) < dsRows && dsCols > 0)
            *(*(DS + (i + 2)) + 0) = rowSum;
    }

    // Returns the status codes
    if(dsRows >= reqRows && dsCols >= reqCols){
        if(dsRows == reqRows && dsCols == reqCols){
            return 1; // Exact fit
        }else{
            return 2; // Oversized
        }
    }
    return -1; // Partial fit
}
