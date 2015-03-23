
#include <cstdlib>
#include <ios>
#include "polynomial.h"
#include <vector>

using namespace std;

//Default constructor for polynomial 
Polynomial::Polynomial(): degree(0), coefficients(20,0.0){
}

//Obtains the highest power and coefficients of each, from the user
Polynomial::Polynomial(int myDegree):degree(myDegree), coefficients(20,0.0){
    int num = 0;
    degree = myDegree;
    
    if (degree > 0){
        for (int i = 0; i <= degree; i++){
            if (i == 0) {
                cout << "Enter integer for the constant (x^0) term : ";
            } else {
                cout << "Enter an integer for the x^" << i << " coefficient value:  ";
            }
            cin >> num;
            coefficients[i] = num;
        }
    }
}

//Degree accessor. Gets the degree of the polynomial.
int Polynomial::getDegree() const {
    return degree;
}

//Coefficient accessor. Gets the coefficients value of a certain power. 
double Polynomial::coefficient(int index) {
    return coefficients[index];
}

//Method to change the coefficient of the polynomial to a value specified by the user
void Polynomial::changeCoefficient (double newCoefficient, int index) {
    if (0 <= index && index <= degree) {
        coefficients[index] = newCoefficient;
    }
}

//Overload method to add two polynomials together then returns addition polynomial
Polynomial Polynomial::operator+(const Polynomial& poly) const {
    Polynomial addPoly;
    
    if (degree >= poly.getDegree())
        addPoly.degree = degree;
    else
        addPoly.degree = poly.getDegree();
    
    for (int i = 0; i < addPoly.getDegree(); i++)
        addPoly.coefficients[i] = coefficients[i] + poly.coefficients[i];
    return addPoly;
}

//Overload method to multiply the polynomial by a scaler
void Polynomial::operator*(int scalar) {
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = coefficients[i] * scalar;
    }
}

//Overload method to divide a polynomial by a scaler
void Polynomial::operator/(int scalar){
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = coefficients[i] / scalar;
    }
}

//Overload method to negate a polynomial
void Polynomial::operator-() {
    for (int i = 0; i <= degree; i++){
        coefficients[i] = -1 * coefficients[i];
    }
}

//Print method to print the polynomial to the user. Called by the friend method
void Polynomial::print() {
    for (int i = degree; i >= 0; i--)
        if (i == 0 && coefficients[i]!=0)
            cout << " " << coefficients[i] << "\n" << endl;
        else if (i == 1 && coefficients[i] != 0)
            cout << " " << coefficients[i] << "x + ";
        else if (coefficients[i] != 0)
            cout << " " << coefficients[i] << "x^" << i << " + ";
}

//Overloads the "put" method. Calls the print method and passes in the polynomial to be printed
ostream& operator<<(ostream &output, Polynomial &p) {
    p.print();
    return output;
}
