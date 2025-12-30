#include <iostream>
using namespace std;

int main(){

    int rows = 3, cols =4;

    //allocate 2D array
    int **matrix = new int*[rows];
    for(int i =0; i < rows; i++){
        matrix[i] = new int[cols];
    }

    //fill value
    int value = 1;
    for(int r =0; r < rows; r++){
        for (int c = 0; c <cols; c++){
            matrix[r][c] = value++;
        }
    }

    //print
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }



    //Free each row First
    for (int i=0; i < rows; i++){
        delete[] matrix[i];
    }

    //Then free the array of row pointers
    delete[] matrix;

    return 0;

}

//int *p → p is a pointer to an int
//int **pp → pp is a pointer to a pointer to an int
//Student **sp → sp is a pointer to a pointer to a Student