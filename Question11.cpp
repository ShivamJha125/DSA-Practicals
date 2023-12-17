#include <stdio.h>

// Function to check if a matrix is sparse and return the number of non-zero elements
int check_sparse(int row, int col, int arr[row][col]) {
    int count = 0, i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] != 0)
                count++;
        }
    }
    if (count > (row * col) / 2)
        return 0;
    else
        return count;
}

// Function to convert a matrix to a compact form
void matrix_conversion(int compactMatrix[][3], int arr[][5], int row, int col) {
    int k = 0, i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = arr[i][j];
                k++;
            }
        }
    }
}

int main() {
    int row = 4;
    int col = 5;
    int arr[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    int count = check_sparse(row, col, arr);
    printf("Number of non-zero elements: %d\n", count);

    int compactMatrix[count][3];
    matrix_conversion(compactMatrix, arr, row, col);

    printf("Compact Matrix:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", compactMatrix[i][0], compactMatrix[i][1], compactMatrix[i][2]);
    }

    return 0;
}

