#include "Complex.h"

int main(){
    Complex c(3, 2);
    Complex c1(4, 6);
    Complex c2(1, -1);
    Complex rez = c.mult(c1);
    std::cout<<rez.show_compl();
    std::cout<<c2.abs()<<'\n';
    std::string polar = c1.compute_polar();
    std::cout<<polar;
}