
#include "matrix.h"

using namespace std;

//Default Constructor
Matrix::Matrix():row(0), col(0) {
}

//Constructor to set size of rows and colomns to zero
Matrix::Matrix(std::vector< std::vector<int> > &newMatrix) :row(newMatrix.size()), col(newMatrix[0].size()), myMatrix(newMatrix){
 
}

//Sets the matrix values to 0. 
void Matrix::setMatrix(int newRow, int newCol){
    row = newRow;
    col = newCol;
    std::vector< std::vector<int> > matrixB(newRow, std::vector<int>(newCol));
    myMatrix = matrixB; 
     for(int i=0; i<row; i++){
       for(int j=0; j<col; j++){
           matrixB[i][j] = 0; 
       }
     }   
 }
 
//Accessor method that returns value of matrix at position (i,j))
int Matrix::get_value(int i, int j) const {
    return myMatrix[i][j]; 
 }
 
//Mutator method to change the value of matrix at position (i,j))
void Matrix::set_value(int i, int j, int value){
     myMatrix[i][j] = value;
 }
 
//Transpose method to transpose the matrix
Matrix Matrix::transpose() const{
     Matrix transMatrix;
     transMatrix.setMatrix(row, col);
     for(int i=0; i<row; i++){
         for(int j=0; j<col; j++){
             transMatrix.set_value(i, j, myMatrix[i][j]); 
         }
     }
     return transMatrix; 
 } 
 
//Overload method to subtract to matrices
Matrix Matrix::operator-(const Matrix matrixB) const {
     if(matrixB.row == row && matrixB.col == col){
        Matrix subMatrix;
        subMatrix.setMatrix(row, col);
     
        for(int i=0; i< row; i++){
            for(int j=0; j<col; j++){
                int difference = myMatrix[i][j] - matrixB.get_value(i, j);
                    subMatrix.set_value(i, j, difference);  
            }
         }  
        return subMatrix;
    } else {
         std::cerr << "Dimensionality of two matrices does not match\n";
         return *this;
     }
 }
 
//Overload method to multiply two matrices
Matrix Matrix::operator*(const Matrix matrixB) const{
    if(matrixB.row == row && matrixB.col == col){
        Matrix multiMatrix;
        multiMatrix.setMatrix(row, col);  
  
        for(int i=0; i< row; i++){
             for(int j=0; j<col; j++){
                 multiMatrix.set_value(i, j, 0);
                 for(int k=0; k<col; k++){
                     int product = multiMatrix.get_value(i, j) + (myMatrix[i][k] * matrixB.get_value(k,j));
                    multiMatrix.set_value(i,j,product);    
             }
         }   
     }
     return multiMatrix; 
 } else {
         std::cerr << "Dimensionality of two matrices does not match\n";
         return *this;
     }
 }
 
//Overload method to multiply  a matrix by a scaler 
Matrix Matrix::operator*(int scaler) const{
     Matrix scalerMatrix;
     scalerMatrix.setMatrix(row, col); 
    
     for(int i=0; i< row; i++){
         for(int j=0; j<col; j++){
              scalerMatrix.set_value(i, j, myMatrix[i][j] * scaler);    
         }   
     }
      return scalerMatrix; 
  }
  
//Overload "put" operator to print matrices to user
std::ostream& operator<<(std::ostream &output, const Matrix &matrixOut){
      
      for(int i=0; i < matrixOut.row ; i++){
          for(int j=0; j < matrixOut.col; j++){
              output << matrixOut.get_value(i, j) << " ";
          }
          output << std::endl;
      }
      return output; 
  }
 
