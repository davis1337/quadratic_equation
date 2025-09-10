#include "equation.h"

int main() {
    
    Coefficients coeffs = input_coefficients();
    solve_equation(coeffs.a, coeffs.b, coeffs.c);
    
    return 0;
}