#ifndef MATRIX_H
#define	MATRIX_H

#include <vector>
#include <iostream>


class Matrix{
    
private: 
   int row, col, size; 
   std::vector< std::vector<int> > myMatrix; 
    
public :
  
     Matrix();    //Default Constructor
    //Matrix constructor to create a matrix by passing a vector of vectors
    explicit Matrix(std::vector< std::vector<int> > &newMatrix);  
    void setMatrix(int newRow, int newCol);         //Sets the number of rows and colomns of a matrix to 0
    int get_value(int i, int j) const;              //Accessor method that returns value at position (i,j)
    void set_value(int i, int j, int value);        //Mutator method that changes the value at position (i, j)
    Matrix operator*(const Matrix matrixB) const;   //Overloaded (*) method to multiply two matrices together
    Matrix operator-(const Matrix matrixB) const;   //Overloaded (-) method to subtract a one matrix from another
    Matrix operator*(int scaler) const;             //Overloaded (*) method to multiply a matrix by a scaler
    Matrix transpose()const;                        //Transpose method to transpose a method
    friend std::ostream &operator<<(std::ostream &output, const Matrix &matrixOut);  //Overload "put" method
};

#endif	/* MATRIX_H */

