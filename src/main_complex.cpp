#include "Complex.h"
#include <vector>

Complex gesammtSumme(std::vector<Complex> complex_numbers){
    Complex summe(0, 0);
    for(auto element = complex_numbers.begin(); element != complex_numbers.end(); ++element){
        summe = summe.add(*element);
    }
    return summe;
}

int main(){
    std::vector<Complex> complex_numbers;
    double realPart, imaginaryPart;
    int numberElements;
    std::cin>>numberElements;
    for(int index = 0; index < numberElements; index++){
        std::cin>>realPart>>imaginaryPart;
        complex_numbers.push_back(Complex(realPart, imaginaryPart));
    }
    std::cout<<gesammtSumme(complex_numbers).show_compl();
    return 0;
}