//John Hoffman - F00555643
//CSC 543
//Assignment 2 - Array Implementation
//09/05/2021

#include<iostream>
using namespace std;

int main(){
    
    //Initializing the example matrix from the assignment
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4},
        {0 , 0 , 5 , 7 , 0},
        {0 , 0 , 0 , 0 , 0},
        {0 , 2 , 6 , 0 , 0}
    };

    //Finding the total number of non-zero values in the matrix
    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    //Initialize the compact matrix, the final dimensions will be the 3 "rows" for each of the two index and the value
    //and the size is the number of columns, or how many non-zero values it will contain
    int compactMatrix[3][size];

    //Generate the new compact matrix
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i; //Setting the row index number
                compactMatrix[1][k] = j; //Setting the column index number
                compactMatrix[2][k] = sparseMatrix[i][j]; //Setting the value
                k++;
            }
        }
    }

    //Output the new compact matrix
    cout << "Final Compact Matrix:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", compactMatrix[i][j]);
        }
        cout << "\n";
    }

    return 0;
}