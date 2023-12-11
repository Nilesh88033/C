#include <stdio.h>

// Function to read a sparse matrix and store it in the array X
void readSparseMatrix(int X[][3]) {
    int rows, cols, t;

    // Input number of rows, columns, and nonzero terms
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of nonzero terms: ");
    scanf("%d", &t);

    // Store matrix dimensions and number of nonzero terms in X(0,*)
    X[0][0] = rows;
    X[0][1] = cols;
    X[0][2] = t;

    // Input and store nonzero elements in X
    for (int i = 1; i <= t; i++) {
        printf("Enter row, column, and value for term %d (separated by space): ", i);
        scanf("%d %d %d", &X[i][0], &X[i][1], &X[i][2]);
    }
}

// Function to multiply two sparse matrices and store the result in X
void multiplySparseMatrices(int X1[][3], int X2[][3], int resultX[][3]) {
    int rows1 = X1[0][0];
    int cols1 = X1[0][1];
    int t1 = X1[0][2];

    int rows2 = X2[0][0];
    int cols2 = X2[0][1];
    int t2 = X2[0][2];

    // Check if the matrices are compatible for multiplication
    if (cols1 != rows2) {
        printf("Matrices are not compatible for multiplication.\n");
        return;
    }

    // Initialize the result matrix dimensions and number of nonzero terms
    resultX[0][0] = rows1;
    resultX[0][1] = cols2;
    resultX[0][2] = 0; // Initialize the number of nonzero terms to 0

    // Loop through each row of the first matrix
    for (int i = 1; i <= rows1; i++) {
        // Loop through each column of the second matrix
        for (int j = 1; j <= cols2; j++) {
            int sum = 0;

            // Loop through each element of the row in the first matrix
            for (int k = 1; k <= t1; k++) {
                // Check if there is a corresponding element in the column of the second matrix
                if (X1[k][0] == i && X2[k][1] == j) {
                    sum += X1[k][2] * X2[k][2];
                }
            }

            // If the sum is not zero, store it in the result matrix
            if (sum != 0) {
                resultX[++resultX[0][2]][0] = i;
                resultX[resultX[0][2]][1] = j;
                resultX[resultX[0][2]][2] = sum;
            }
        }
    }
}

// Function to display a sparse matrix in a readable format
void displaySparseMatrix(int X[][3]) {
    int rows = X[0][0];
    int cols = X[0][1];
    int t = X[0][2];

    // Display the matrix in the usual format
    printf("Sparse Matrix:\n");
    for (int i = 1; i <= t; i++) {
        printf("(%d, %d): %d\n", X[i][0], X[i][1], X[i][2]);
    }
    printf("\n");
}

int main() {
    int MAX_TERMS = 100; // Adjust this based on the maximum possible number of nonzero terms

    int X1[MAX_TERMS][3];           // First sparse matrix
    int X2[MAX_TERMS][3];           // Second sparse matrix
    int resultX[MAX_TERMS][3];      // Result of multiplication

    // Read and store the first sparse matrix
    printf("Enter details for the first sparse matrix:\n");
    readSparseMatrix(X1);

    // Read and store the second sparse matrix
    printf("Enter details for the second sparse matrix:\n");
    readSparseMatrix(X2);

    // Display the first sparse matrix
    printf("First ");
    displaySparseMatrix(X1);

    // Display the second sparse matrix
    printf("Second ");
    displaySparseMatrix(X2);

    // Multiply the sparse matrices
    multiplySparseMatrices(X1, X2, resultX);

    // Display the result of multiplication
    printf("Product ");
    displaySparseMatrix(resultX);

    return 0;
}
