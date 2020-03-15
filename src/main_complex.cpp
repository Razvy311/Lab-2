#include "Complex.h"
#include "Rational.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Complex gesammtSummeC(std::vector<Complex> complex_numbers){
    Complex summe(0, 0);
    for(auto element = complex_numbers.begin(); element != complex_numbers.end(); ++element){
        summe = summe.add(*element);
    }
    return summe;
}

Rational gesammtSummeR(std::vector<Rational> rational_numbers){
    Rational summe(0);
    for(auto element = rational_numbers.begin(); element != rational_numbers.end(); ++element){
        summe = summe.add(*element);
    }
    return summe;
}

int main(){
    std::vector<Complex> complex_numbers;
    std::vector<Rational> rational_numbers;

//    // Reading and creating all the elements.
//    int numberElements;
//    std::cin >> numberElements;
//
//    double realPart, imaginaryPart;
//    for(int index = 0; index < numberElements; index++){
//        std::cin >> realPart >> imaginaryPart;
//        complex_numbers.push_back(Complex(realPart, imaginaryPart));
//    }

	// Main for complex numbers.
    cout << "Complex Numbers: " << endl;

    // Create all the elements.
    complex_numbers.push_back(Complex(1, 2));
    complex_numbers.push_back(Complex(1, 0.5));
    complex_numbers.push_back(Complex(0, 0.2));

    // Sort the vector.
    sort(complex_numbers.begin(), complex_numbers.end());

    // Print all the elements.
    cout << "Elements (Sorted): " << endl;
    for(unsigned int i = 0; i < complex_numbers.size(); ++i)
    	cout << "  - " << complex_numbers[i].show_compl() << " | " << complex_numbers[i].show_exp() << " | " << complex_numbers[i].compute_polar() << endl;

    // Calculate the sum and print it to the screen.
    cout << endl << "Gesammtsumme: " << gesammtSummeC(complex_numbers).show_compl() << endl << endl;

    // Main for rational numbers.
    cout << "Rational Numbers: " << endl;

    // Create all the elements.
    rational_numbers.push_back(Rational(2.6));
    rational_numbers.push_back(Rational(-2));
    rational_numbers.push_back(Rational(-329.222));

    // Sort the vector.
    sort(rational_numbers.begin(), rational_numbers.end());

    // Print all the elements.
	cout << "Elements (Sorted): " << endl;
	for(unsigned int i = 0; i < rational_numbers.size(); ++i)
		cout << "  - " << rational_numbers[i].show_rational() << " | " << rational_numbers[i].show_exp() << endl;

	// Calculate the sum and print it to the screen.
	cout << endl << "Gesammtsumme: " << gesammtSummeR(rational_numbers).show_rational();

    return 0;
}
