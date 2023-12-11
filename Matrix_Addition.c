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

// Function to add two sparse matrices and store the result in X
void addSparseMatrices(int X1[][3], int X2[][3], int resultX[][3]) {
    int rows1 = X1[0][0];
    int cols1 = X1[0][1];
    int t1 = X1[0][2];

    int rows2 = X2[0][0];
    int cols2 = X2[0][1];
    int t2 = X2[0][2];

    // Check if the matrices are compatible for addition
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices are not compatible for addition.\n");
        return;
    }

    // Initialize the result matrix dimensions and number of nonzero terms
    resultX[0][0] = rows1;
    resultX[0][1] = cols1;
    resultX[0][2] = 0; // Initialize the number of nonzero terms to 0

    int i = 1, j = 1;
    while (i <= t1 && j <= t2) {
        if (X1[i][0] < X2[j][0] || (X1[i][0] == X2[j][0] && X1[i][1] < X2[j][1])) {
            // Copy the element from the first matrix to the result
            resultX[++resultX[0][2]][0] = X1[i][0];
            resultX[resultX[0][2]][1] = X1[i][1];
            resultX[resultX[0][2]][2] = X1[i][2];
            i++;
        } else if (X1[i][0] > X2[j][0] || (X1[i][0] == X2[j][0] && X1[i][1] > X2[j][1])) {
            // Copy the element from the second matrix to the result
            resultX[++resultX[0][2]][0] = X2[j][0];
            resultX[resultX[0][2]][1] = X2[j][1];
            resultX[resultX[0][2]][2] = X2[j][2];
            j++;
        } else {
            // Add the values of corresponding elements from both matrices
            int sum = X1[i][2] + X2[j][2];
            if (sum != 0) {
                // Copy the nonzero sum to the result
                resultX[++resultX[0][2]][0] = X1[i][0];
                resultX[resultX[0][2]][1] = X1[i][1];
                resultX[resultX[0][2]][2] = sum;
            }
            i++;
            j++;
        }
    }

    // Copy any remaining elements from the first matrix to the result
    while (i <= t1) {
        resultX[++resultX[0][2]][0] = X1[i][0];
        resultX[resultX[0][2]][1] = X1[i][1];
        resultX[resultX[0][2]][2] = X1[i][2];
        i++;
    }

    // Copy any remaining elements from the second matrix to the result
    while (j <= t2) {
        resultX[++resultX[0][2]][0] = X2[j][0];
        resultX[resultX[0][2]][1] = X2[j][1];
        resultX[resultX[0][2]][2] = X2[j][2];
        j++;
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
    int resultX[MAX_TERMS][3];      // Result of addition

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

    // Add the sparse matrices
    addSparseMatrices(X1, X2, resultX);

    // Display the result of addition
    printf("Sum ");
    displaySparseMatrix(resultX);

    return 0;
}
