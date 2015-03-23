#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H
#include <vector>
#include <iostream>

class Polynomial {
    
private:
    
    std::vector<double> coefficients;     //vector of coefficients
    int degree;                           //size of coefficient vector
   
public:

    Polynomial();                        //Default Constructor
    Polynomial(int);                     //Constructor to obtain the degree and coefficients of a polynomial. 
    int getDegree() const;               //Returns the degree of the polynomial
    double coefficient(int);             //Returns the coefficient of the polynomial stored in coefficients vector
    void changeCoefficient(double, int); //Replaces the coefficient with a new value
    void operator*(int);                 //Performs multiplication of a polynomial by a scaler
    Polynomial operator+(const Polynomial&)const ;  //Performs addition of two polynomials 
    void operator/(int);                            //Preforms division of a polynomial by a scaler
    void operator-();                               //Overloads the negation operator to negate a polynomial
    void print();                                   //Overloads the "put" operator to output a polynomial
    friend std::ostream& operator << (std::ostream &output, Polynomial &p);       //Friend method for printing 

};

#endif	/* POLYNOMIAL_H */

