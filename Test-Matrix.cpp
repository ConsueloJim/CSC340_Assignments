/* ************************************************************************************************************
 * ************************************************************************************************************
 * Description : 
 * 
 * The purpose of this program is to implement the Matrix class using matrix.h and matrix.cpp. It first gets 
 * the dimension and values of two matrices and performs basic operations on them. It will change the value at 
 * a certain position of a matrix, subtract two matrices,multiply two matrices, transpose a matrix and multiply 
 * a matrix by a scaler.
 *
 * *************************************************************************************************************
 * *************************************************************************************************************
 */


#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
   
    
    cout << "------ This is a Test of the Matrix Class Implementation ------\n " << endl; 
    Matrix matrix1; 
    cout << "Matrix 1 was created using the default constructor.\n" << endl; 
    
    vector< vector<int> > myMatrix(4, vector<int>(4));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            myMatrix[i][j]=1;
        }
    }
    
    Matrix matrix2(myMatrix);
    cout << "Matrix 2 was created by passing a vector of vectors into the Matrix constructor\n" << matrix2 << endl; 
    
    matrix1.setMatrix(4, 4);
    cout << "Matrix 1 is set by calling the setMatrix method.\n" << endl;
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            matrix1.set_value(i, j, 2);
        }
    }
    
    cout << "Matrix 1's values have all been set to 2\n" << matrix1 << endl; 
    cout << "The values at [2][2] in Matrix 1 is " << matrix1.get_value(2,2) << endl;
    
    matrix2.set_value(0, 3, 5);
    cout << "Matrix 2's value at [0][3] now equals 5\n" << matrix2 << endl; 
    
    Matrix transMatrix = matrix2.transpose();
    cout << "transMatrix was created by calling the transpose method:\n" << transMatrix << endl; 
    
    Matrix multiMatrix = matrix1*matrix2; 
    cout << "The Product of Matrix 1 x Matrix 2 equals : " << multiMatrix << endl; 
    
    Matrix scalerMatrix = matrix1 * 2; 
    cout << "\nMatrix 1 scaled by 2 equals : " << scalerMatrix << endl;
    
    Matrix subMatrix = scalerMatrix - matrix1;
    cout << "The ScalerMatrix minus Matrix 1 equals : " << subMatrix << endl;
    
    cout << "-------- Now testing the Matrix Interface --------\n";
    cout << endl;
    
    int row =0;
    int col = 0;
    int value = 0;
    
    cout << "Enter the dimensions of the first square matrix:\n";
    cin >> row;
    cin >>col;
    vector< vector<int> > firstMatrix(row, vector<int>(col));
    for(int i=0; i<row; i++){
        cout << "Enter " << col << " integer values for row " << i+1 << "(separated by spaces): "; 
        for(int j=0; j<col; j++){
            cin >> firstMatrix[i][j];
        }
    }
    
    Matrix matrix3(firstMatrix);
    cout << endl;
    
    cout << "Enter another matrix with the same dimensions as the first matrix :\n";
    cin >> row;
    cin >>col; 
    cout << endl;
    vector< vector<int> > secondMatrix(row, vector<int>(col));
    for(int i=0; i<row; i++){
        cout << "Enter " << col << " integer values for row " << i+1 << " (separated by spaces): "; 
        for(int j=0; j<col; j++) {
            cin >> secondMatrix[i][j];
        }
    }
    
    Matrix matrix4(secondMatrix);
    cout << endl; 
    
    cout << "What value would you like to get from your first matrix? Enter (row col) : ";
    cin >> row >> col; 
    cout << "The value at [" << row << "][" << col << "] is " << matrix3.get_value(row-1, col-1) << endl;
    cout << endl;
    
    cout << "What value would you like to change in the second matrix? Enter (row col value) : ";
    cin >> row >> col >> value;
    matrix4.set_value(row-1, col-1, value);
    cout << endl;
    
    cout << "The value at [" << row << "][" << col << "] is now " << matrix4.get_value(row-1, col-1) << endl;
    cout << endl; 
    
    cout << "Your first matrix transposed is : \n" << matrix3.transpose() << endl;
    cout << endl;
    
    cout << "The first matrix * second matrix is : \n" << (matrix3 * matrix4) << endl;
    cout << endl; 
    
    int scaler = 0;
    cout << "Enter an integer to multiply your first matrix by : \n";
    cin >> scaler;
    cout << endl;
    
    cout << "First Matrix * " << scaler << " = \n" << matrix3*scaler << endl;
    cout << endl;
    
    cout << "First Matrix - Second Matrix = \n" << matrix3*matrix4 << endl;
    cout << endl; 
    
}

