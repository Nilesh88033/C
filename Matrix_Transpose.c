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

// Function to transpose a sparse matrix and store it in the array X
void transposeSparseMatrix(int X[][3], int transposeX[][3]) {
    int rows = X[0][0];
    int cols = X[0][1];
    int t = X[0][2];

    // Initialize the transpose matrix dimensions and number of nonzero terms
    transposeX[0][0] = cols;
    transposeX[0][1] = rows;
    transposeX[0][2] = t;

    // Compute the transpose of the matrix
    int count = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= t; j++) {
            if (X[j][1] == i) {
                transposeX[count][0] = i;
                transposeX[count][1] = X[j][0];
                transposeX[count][2] = X[j][2];
                count++;
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

// Function to display the transpose of a sparse matrix in a readable format
void displayTransposeSparseMatrix(int transposeX[][3]) {
    int rows = transposeX[0][0];
    int cols = transposeX[0][1];
    int t = transposeX[0][2];

    // Display the transpose matrix in the usual format
    printf("Transpose of Sparse Matrix:\n");
    for (int i = 1; i <= t; i++) {
        printf("(%d, %d): %d\n", transposeX[i][0], transposeX[i][1], transposeX[i][2]);
    }
    printf("\n");
}

int main() {
    int MAX_TERMS = 100; // Adjust this based on the maximum possible number of nonzero terms

    int X[MAX_TERMS][3];            // Original sparse matrix
    int transposeX[MAX_TERMS][3];   // Transpose of the sparse matrix

    // Read and store the sparse matrix
    readSparseMatrix(X);

    // Display the original sparse matrix
    displaySparseMatrix(X);

    // Transpose the sparse matrix
    transposeSparseMatrix(X, transposeX);

    // Display the transpose of the sparse matrix
    displayTransposeSparseMatrix(transposeX);

    return 0;
}
