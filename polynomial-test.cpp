/* ************************************************************************************************
 * ************************************************************************************************
 * 
 * Description : 
 * 
 * The purpose of this program is to implement a polynomial class
 * that will interact with the user to obtain the highest power and 
 * coefficients of the polynomial. It then tests basic operator overloading by 
 * multiplying and dividing a polynomial by a scaler, adding two polynomials 
 * together, negating a polynomial and printing the polynomial and subsequent 
 * results to the user. 
 *
 * ************************************************************************************************
 * ************************************************************************************************
 */

#include <cstdlib>
#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
    
    int power = 0;  //Holds the number of terms that are in the polynomial, depends on highest power
    int index = 0;  //Keeps track of what coefficient corosponds to which term
    int scalar = 0; //Holds integer value to use for multiplication and division
    double newCoefficient = 0;
    
    cout<< "------- This is a Test of the Polynomial Class Implementation -------\n";
    cout << endl;
    
    cout << "Enter the highest power of the polynomial : ";
    cin >> power;
    Polynomial p1(power);
    cout << "The Polynomial is : " << p1;

    cout << "The Polynomials Degree is : " << p1.getDegree() << endl;

    cout << "Enter the coefficients power to view it : ";
    cin >> index;
   
    cout << "Coefficient is : " << p1.coefficient(index) << endl;

    cout << "Enter a power to modify its coefficient : ";
    cin >> index;
    
    cout << "Enter the new coefficient : ";
    cin >> newCoefficient;
    p1.changeCoefficient(newCoefficient, index);

    cout << "The Result is: " << p1;
    
    cout << "----------------------- Addition -----------------------" << endl;
    cout << endl;
    cout << "Enter the highest power of the first polynomial : ";
    cin >> power;
    Polynomial p2(power);
    
    cout << "Enter the highest power of the second polynomial : ";
    cin >> power;
    Polynomial p3(power);
    
    Polynomial p4;
    p4 = p2 + p3;
    cout << "The first Polynomial plus the second polynomial is : " << p4;

    cout << "-------------------- Multiplication -------------------" << endl;
    cout << endl;
    cout << "Enter the highest power of the polynomial : ";
    cin >> power;
    Polynomial p5(power);
    cout << endl;
    
    cout << "Enter an integer for polynomial multiplication : ";
    cin >> scalar;

    cout << "The Polynomial before multiplication is : " << p5;
    p5  * scalar;

    cout << "The polynomial multiplied by "<< scaler << " is : " << p5;
    cout << endl;

    cout << "---------------------- Division ------------------------" << endl;
    cout << endl;
    cout << "Enter the highest power of the polynomial : ";
    cin >> power;
    Polynomial p6(power);
    
    cout << "Enter an integer to divide the polynomial by : ";
    cin >> scalar;
    
    cout << "The Polynomial before division is: " << p6;
    p6 / scalar;

    cout << "The Polynomial divided by " << scaler << " is : " << p6;
    cout << endl;
    
    cout << "---------------------- Negation ---------------------" << endl;
    cout << endl;
    - p6;
    cout << "The negation of  " << p6 << " is : " << p6;
    cout << endl;
    cout << "--------------- This is the end of the Polynomial Class Implementation --------------";

    return 0;
   
}

