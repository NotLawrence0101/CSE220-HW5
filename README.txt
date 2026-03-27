Homework 5 – Pointer Operations
CSE 220 – Spring 2026

Name: Lawrence Wong
SBU ID: 116408194

The test cases are in the file "test_matrix.c", which sections off each section of the matrix homework with comments.

SparseMatrix Test Cases:
• Tests for basic use of counting nonzero entries within the maximums.
• Tests for when the nonzero entries exceeds the max row and columns, returns -1.
• Tests for zero matrices, returns 0.
• Tests for when the row is larger.
• Tests for when the column is larger.

HadamardProduct Test Cases:
• Tests for basic use for matching sizes of M, N, and A arrays and returns 1 with the modified array.
• Tests for when A is larger than both M and N sizes, returns 2.
• Tests for when A is too small and M and N matches, returns -3.
• Tests for when M and N are different sizes and A fits some of the product, returns -1.
• Tests for when one matrix is filled with 0s, returns the apporpriate number and a zeroed out 2D array.
• Tests for padding for larger sizes of the A array.
• Tests for overlapping entries.

Matrix Multiplcation Test Cases:
• Tests for basic use when the M column and N Row sizes matches, returns 1.
• Tests for when A is bigger than the resulting multiplication, returns 2.
• Tests for when A is too small for the multiplcation, returns -3.
• Tests for when M and N do not match and A is too small, returns -2.
• Tests for when M and N do not match and A is bigger than the resulting partial multiplication, returns -1.
• Tests for multiplying the identity matrix, which results in the same matrix it is multiplied by and returns 1.

DiagonalSum Test Cases:
• Tests for basic use, when the A and DS arrays match and returns 1.
• Tests for when DS is oversized for the result, returns 2.
• Tests for when DS is undersized for the result, returns -1 and changes the array to be partial.
• Tests for when A is a not a square matrix, returns 1 and changes the array accordingly.
• Tests for when A is a 1D array with one entry, returns 1 accordingly.
• Tests for when DS columns and rows don't match A, returns -1.
• Tests for when A is a zero matrix, which changes the DS array to be a zero matrix and returns 1.
