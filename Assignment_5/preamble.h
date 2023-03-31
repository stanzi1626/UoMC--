// File to introduce the program and say what the program does

// This program defines a matrix class and implements the following operations:
// 1. Default constructor -> creates a 1x1 matrix with a single element
// 2. Parameterized constructor -> creates a mxn matrix
// 3. Copy constructor -> creates a copy of a matrix
// 4. Move constructor -> creates a matrix by moving an existing matrix
// 5. Destructor -> deletes a matrix
// 6. Access functions -> returns the number of rows and columns in a matrix
// 7. Index function -> returns the position in the array of a given element
// 8. Overloaded () operator -> returns a reference to a given element
// 9. Overloaded = operator -> assigns a matrix to another matrix
// 10. Overloaded + operator -> adds two matrices
// 11. Overloaded - operator -> subtracts two matrices
// 12. Overloaded * operator -> multiplies two matrices
// 13. Remove_row_column function -> returns a submatrix with row m and column n removed
// 14. Determinant function -> returns the determinant of a matrix
// 15. Overloaded << operator -> prints a matrix
// 16. Overloaded >> operator -> reads a matrix

// The main function tests the matrix class by creating 3 matrices (one of which can be inputted by the user).
// The 3 matrices are defined as:
// 1. matrixA - a 3x3 matrix: [1 2 3] [9 8 7] [4 2 6] (if not defined by the user)
// 2. matrixB - a 3x3 matrix: [5 5 4] [1 2 3] [6 9 8]
// 3. matrixC - a 2x3 matrix: [3 4 1] [2 5 6]
// and performing the following operations:
// 1. Print the matrices
// 2. Add matrixA and matrixB
// 3. Subtract matrixA and matrixB
// 4. Multiply matrixA and matrixB
// 5. Multiply matrixA and matrixC
// 6. Calculate the determinant of matrixA, matrixB and matrixC
// 7. Demonstrate self-assignment with matrixA
// 8. Copy matrixA to matrixD using the copy constructor
// 9. Copy matrixA to matrixE using the copy assignment operator
// 10. Manipulate matrixA and demonstrate deep copy of matrixD and matrixE
// 11. Move matrixA to matrixF using the move constructor
// 12. Move matrixD to matrixG using the move assignment operator
// 13. Take in user matrix, in the form [a,b,...][c,d,...][...], and print it