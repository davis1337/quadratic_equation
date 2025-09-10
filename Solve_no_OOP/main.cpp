#include "equation.h"

int main() {
    cout << "============= Solving quadratic equation =============" << endl;
    Coefficients coeffs = input_coefficients();
    solve_equation(coeffs.a, coeffs.b, coeffs.c);
    
    return 0;
}