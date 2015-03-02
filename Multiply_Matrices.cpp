
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

void multiply_matrices( vector< vector<int>> matrixA, vector< vector<int>> matrixB, int row_A, int row_B, int col_A, int col_B);

int main() {
    
    int row_A,col_A, row_B, col_B;                     //Declare variables and vector matrices
    vector< vector<int>> matrixA;
    vector< vector<int>> matrixB;

    cout << "Enter the number of rows and columns of Matrix A:::\n\n";
    cin >> row_A >> col_A;                             //cin the number or rows and columns for Matrix A
    matrixA.resize(row_A, vector<int>(col_A));         //resize Matrix A for the number of rows and columns entered
    
    cout <<"\n\nEnter values for Matrix A :::\n\n";
    
    for(int i = 0; i < row_A; i++){                    //For each row enter the value for that [row_A][colomn_A] i.e. for row[0],colomn[0] enter value, i++,j++ --> [0][1]...
        for( int j = 0; j < col_A; j++){
            cin >> matrixA[i][j];
        }
        cout << "\n";
    }
    
    cout <<"\n-----------------------------------------------------\n";
    
    cout << "Enter the number of rows and colomns of Matrix B:::\n\n";
    cin >> row_B >> col_B;
    matrixB.resize(row_B, vector<int>(col_B));
   
    cout << "\n\nEnter the values for Matrix B :::\n\n";
    for(int i = 0; i < row_B; i++){
        for( int j = 0; j < col_B; j++){
            cin >> matrixB[i][j];
        }
        cout <<"\n";
    }
    
    multiply_matrices(matrixA, matrixB, row_A, row_B, col_A, col_B );

    
    return 0;
   }


void multiply_matrices(vector< vector<int>>matrixA, vector< vector<int>> matrixB, int row_A, int row_B, int col_A, int col_B){
    
    vector< vector<int>> product;         //Declare product vector
    
    cout << "\n\nMatrix A  : \n\n";       //Print out Matracies
    for(int i = 0; i < row_A; i++){
        for( int j = 0; j < col_A; j++){
            cout << "\t"<< matrixA[i][j];
        }
        cout << "\n\n";
    }
    
    cout <<"\n-----------------------------------------------------\n";

    cout <<"\n\n Matrix B : \n\n";
    for(int i=0; i < row_B; i++){
        for(int j=0; j<col_B;j++){
            cout << "\t"<<matrixB[i][j];
        }
        cout << "\n\n";
    }
    
    if(row_B == col_A){             //Perform multiplication only if the colomns in A equal the number of rows in B
        product.resize(row_B, vector<int>(col_A));   //Resize product vector so that it has the same amount of rows as B and colomns of A
        
        for(int i=0; i<row_A; i++){
            for(int j=0; j<col_B; j++){
                product[i][j]=0;
                for(int k=0; k<row_B; k++){
                    product[i][j] = product[i][j]+matrixA[i][k]*matrixB[k][j];
                }
            }
        }

    cout <<"\n\nMultiplication of Matrix A and Matrix B  :\n\n";      //Print the product vector.
    
        for(int i=0; i<row_A; i++){
            for(int j=0; j<col_B; j++){
                cout << "\t" << product[i][j];
            }
            cout << "\n\n";
        }
    }
    else{ cout << "\n\nMultiplication is not possible becuause the number of colomns in A must equal the number of rows in B";}

}
