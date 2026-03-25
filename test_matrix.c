
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

Test(HadamardProduct, compatible)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

/*----------------------------------------------------
  3. Multiplication Test Cases
----------------------------------------------------*/

Test(Multiplication, simple_case)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

/*----------------------------------------------------
  4. Diagonal Sum Test Cases
----------------------------------------------------*/

Test(DiagonalSum, square_matrix)
{
    int D[4] = {3,3,5,5};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[5][5];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}
