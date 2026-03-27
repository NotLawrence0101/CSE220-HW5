
#include <criterion/criterion.h>
#include "matrix.h"

/*----------------------------------------------------
  1. Sparse Matrix Test Cases
----------------------------------------------------*/
Test(SparseMatrix, basic_sparse_test)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,0},
        {0,0,0},
        {0,0,3}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 2);
}

Test(SparseMatrix, zero_sparse_test)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 0);
}

Test(SparseMatrix, Col2_sparse_test)
{
    int D[2] = {5,2};

    int M[5][2] = {
        {1,2},
        {4,5},
        {0,0},
        {3,0},
        {0,0}
    };

    int S[3][5];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 5);
}

Test(SparseMatrix, Max_Nonzero_sparse_test)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,2,0},
        {0,5,0},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 3);
}

Test(SparseMatrix, More_Nonzero_sparse_test)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,2,3},
        {1,5,2},
        {0,0,1}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, -1);
}

Test(SparseMatrix, first_smaller_sparse_test)
{
    int D[2] = {2,3};

    int M[2][3] = {
        {1,0,2},
        {0,1,0}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 3);
}

Test(SparseMatrix, second_smaller_sparse_test)
{
    int D[2] = {3,2};

    int M[3][2] = {
        {1,0},
        {0,1},
        {0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 2);
}

Test(SparseMatrix, two_array_sparse_test)
{
    int D[2] = {2,2};

    int M[2][2] = {
        {1,0},
        {0,1}
    };

    int S[3][2];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 2);
}

Test(SparseMatrix, fill_sparse_test)
{
    int D[2] = {5,2};

    int M[5][2] = {
        {1,0},
        {0,0},
        {2,0},
        {0,0},
        {0,0}
    };

    int S[3][5];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 2);
}

Test(SparseMatrix, bigger_sparse_test)
{
    int D[2] = {3,10};

    int M[3][10] = {
        {1,0,2,3,4,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,5},
        {2,0,2,0,0,0,5,0,4,0}
    };

    int S[3][10];

    int result = SparseMatrix(D, M, S);

    cr_assert_eq(result, 10);
}

/*----------------------------------------------------
  2. Hadamard Product Test Cases
----------------------------------------------------*/

Test(HadamardProduct, compatible_HadamardProduct_test)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {5,3},
        {5,3}
    };

    int N[2][2] = {
        {3,5},
        {3,5}
    };

    int A[2][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, 1);
}

Test(HadamardProduct, oversizedA_HadamardProduct_test)
{
    int D[6] = {2,2,2,2,5,5};

    int M[2][2] = {
        {5,3},
        {5,3}
    };

    int N[2][2] = {
        {3,5},
        {3,5}
    };

    int A[5][5];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, 2);
}

Test(HadamardProduct, oversizedMN_HadamardProduct_test)
{
    int D[6] = {3,3,3,3,2,2};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][3] = {
        {2,2,2},
        {2,2,2},
        {2,2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, -3);
}

Test(HadamardProduct, differentMN_fit_HadamardProduct_test)
{
    int D[6] = {3,3,3,2,3,2};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[3][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, -1);
}

Test(HadamardProduct, differentMN_partial_HadamardProduct_test)
{
    int D[6] = {3,3,3,2,2,2};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, -2);
}

Test(HadamardProduct, zero_HadamardProduct_test)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {0,0},
        {0,0}
    };

    int N[2][2] = {
        {3,5},
        {3,5}
    };

    int A[2][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, 1);
}

Test(HadamardProduct, largerA_HadamardProduct_test)
{
    int D[6] = {2,2,2,2,10,10};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {3,5},
        {3,5}
    };

    int A[10][10];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, 2);
}

Test(HadamardProduct, smallA_HadamardProduct_test)
{
    int D[6] = {2,2,2,2,1,1};

    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[2][2] = {
        {3,5},
        {3,5}
    };

    int A[1][1];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, -3);
}

Test(HadamardProduct, partial_HadamardProduct_test)
{
    int D[6] = {2,5,5,2,3,3};

    int M[2][5] = {
        {1,2,3,4,5},
        {5,7,8,9,10}
    };

    int N[5][2] = {
        {3,5},
        {3,5},
        {3,5},
        {3,5},
        {3,5}
    };

    int A[3][3];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, -1);
}

Test(HadamardProduct, biggerCompatible_HadamardProduct_test)
{
    int D[6] = {5,2,5,2,5,2};

    int M[5][2] = {
        {5,3},
        {5,3},
        {5,3},
        {5,3},
        {5,3}
    };

    int N[5][2] = {
        {3,5},
        {3,5},
        {3,5},
        {3,5},
        {3,5}
    };

    int A[5][2];

    int r = HadamardProduct(D, M, N, A);

    cr_assert_eq(r, 1);
}

/*----------------------------------------------------
  3. Multiplication Test Cases
----------------------------------------------------*/

Test(Multiplication, compatible_Multiplication_test)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {2,2},
        {2,2}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, oversizedA_Multiplication_test)
{
    int D[6] = {2,2,2,2,5,5};

    int M[2][2] = {
        {2,2},
        {2,2}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[5][5];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}

Test(Multiplication, partialA_Multiplication_test)
{
    int D[6] = {2,2,2,2,2,1};

    int M[2][2] = {
        {2,2},
        {2,2}
    };

    int N[2][2] = {
        {1,1},
        {1,1}
    };

    int A[2][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-3);
}

Test(Multiplication, uncompatible_partial_Multiplication_test)
{
    int D[6] = {3,2,3,2,2,2};

    int M[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-2);
}

Test(Multiplication, uncompatible_fitA_Multiplication_test)
{
    int D[6] = {3,2,3,2,5,5};

    int M[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[5][5];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(Multiplication, compatibleMNA_Multiplication_test)
{
    int D[6] = {1,3,3,2,1,2};

    int M[1][3] = {
        {2,2,2}
    };

    int N[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int A[1][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, compatibleMN_Multiplication_test)
{
    int D[6] = {1,3,3,2,5,5};

    int M[1][3] = {
        {2,2,2}
    };

    int N[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int A[5][5];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}

Test(Multiplication, zero_Multiplication_test)
{
    int D[6] = {3,3,3,3,3,3};

    int M[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int N[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int A[3][3];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, identity_Multiplication_test)
{
    int D[6] = {3,3,3,3,3,3};

    int M[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int N[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int A[3][3];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, identity_squared_Multiplication_test)
{
    int D[6] = {3,3,3,3,3,3};

    int M[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int N[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int A[3][3];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

/*----------------------------------------------------
  4. Diagonal Sum Test Cases
----------------------------------------------------*/

Test(DiagonalSum, basic_DiagonalSum_test)
{
    int D[4] = {3,3,5,3};

    int A[3][3] = {
        {2,3,4},
        {5,6,7},
        {8,9,10}
    };

    int DS[5][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, oversizedDS_DiagonalSum_test)
{
    int D[4] = {2,2,6,6};

    int A[3][3] = {
        {1,2},
        {3,4}
    };

    int DS[6][6];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}

Test(DiagonalSum, undersizedDS_DiagonalSum_test)
{
    int D[4] = {3,3,2,2};

    int A[3][3] = {
        {2,3,4},
        {5,6,7},
        {8,9,10}
    };

    int DS[2][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, rectangle_DiagonalSum_test)
{
    int D[4] = {2,3,4,3};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
    };

    int DS[4][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, single_DiagonalSum_test)
{
    int D[4] = {1,1,3,2};

    int A[1][1] = {
        {1}
    };

    int DS[3][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, oneD_DiagonalSum_test)
{
    int D[4] = {1,4,3,4};

    int A[1][4] = {
        {1,2,3,4}
    };

    int DS[3][4];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, column_DiagonalSum_test)
{
    int D[4] = {4,1,6,2};

    int A[4][1] = {
        {1},
        {2},
        {3},
        {4}
    };

    int DS[6][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, narrowDS_DiagonalSum_test)
{
    int D[4] = {3,4,5,2};

    int A[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int DS[5][2];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, shortDS_DiagonalSum_test)
{
    int D[4] = {4,2,3,3};

    int A[4][2] = {
        {1,2},
        {3,4},
        {5,6},
        {7,8}
    };

    int DS[3][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, zero_DiagonalSum_test)
{
    int D[4] = {3,3,5,3};

    int A[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int DS[5][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}