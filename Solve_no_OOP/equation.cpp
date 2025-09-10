#include "equation.h"

Coefficients input_coefficients() {
    Coefficients coeffs;
    cout << "Enter coefficents of equation ax^2 + bx + c = 0" << endl;
    
    cout << "Enter a: ";
    if (!(cin >> coeffs.a)) {
        throw invalid_argument("ERROR INPUT: \"a\" should be a number!");
    }
    
    cout << "Enter b: ";
    if (!(cin >> coeffs.b)) {
        throw invalid_argument("ERROR INPUT: \"b\" should be a number!");
    }
    
    cout << "Enter c: ";
    if (!(cin >> coeffs.c)) {
        throw invalid_argument("ERROR INPUT: \"c\" should be a number!!");
    }
    
    if (are_bad_coefficients(coeffs.a, coeffs.b, coeffs.c)) {
        throw invalid_argument("ERROR: (a, b, c) are not a numbers!");
    }
    
    return coeffs;
}

double calculate_discriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

bool are_bad_coefficients(const double a, const double b, const double c) {
    return (isnan(a) || isnan(b) || isnan(c) || 
            isinf(a) || isinf(b) || isinf(c));
}

void print_equation(const double a, const double b, const double c) {
    cout << "Equation: ";
    
    if (a != 0) {
        if (a == 1) cout << "x²";
        else if (a == -1) cout << "-x²";
        else cout << a << "x²";
    }
    
    if (b > 0) {
        if (a != 0) cout << " + ";
        if (b == 1) cout << "x";
        else cout << b << "x";
    } else if (b < 0) {
        cout << " - ";
        if (b == -1) cout << "x";
        else cout << -b << "x";
    }
    
    if (c > 0) {
        if (a != 0 || b != 0) cout << " + ";
        cout << c;
    } else if (c < 0) {
        cout << " - " << -c;
    }
    
    if (a == 0 && b == 0 && c == 0) {
        cout << "0";
    }
    
    cout << " = 0" << endl;
}

void solve_linear(const double b, const double c) {
    if (b == 0) {
        if (c == 0) {
            cout << "The equation has an infinite number of solutions (0 = 0)" << endl;
        } else {
            cout << "The equation dont have solutions (" << c << " = 0)" << endl;
        }
    } else {
        cout << "This is the linear equation (a = 0)" << endl;
        double x = -c / b;
        cout << "x = " << x << endl;
        
        // Проверка решения
        double check = b * x + c;
        cout << "Check: " << b << " * " << x << " + " << c << " = " << check << endl;
    }
}

void check_real_roots(const double a, const double b, const double c, const double x1, 
    const double x2) {
    double check1 = a * x1 * x1 + b * x1 + c;
    double check2 = a * x2 * x2 + b * x2 + c;
    
    cout << "Checking roots:" << endl;
    cout << "   x1 = " << x1 << ": " << check1 << endl;
    cout << "   x2 = " << x2 << ": " << check2 << endl;
    
    if (abs(check1) > numeric_limits<double>::epsilon() || abs(check2) > numeric_limits<double>
    ::epsilon()) {
        cout << "Error with calculate" << endl;
    }
}

void check_single_root(const double a, const double b, const double c, const double x) {
    double check = a * x * x + b * x + c;
    
    cout << "Checking root:" << endl;
    cout << "   x = " << x << ": " << check << endl;
    
    if (abs(check) > numeric_limits<double>::epsilon()) {
        cout << "Error with calculate" << endl;
    }
}

void check_complex_roots(const double a, const double b, const double c, const double re, 
    const double im) {
    
    double real_part = a * (re*re - im*im) + b * re + c;
    double imaginary_part = 2 * a * re * im + b * im;
    
    cout << "Checking complex roots:" << endl;
    /* ТУТ ДОЛЖНА БЫТЬ ПРОВЕРКА КОМПЛЕКСНЫХ КОРНЕЙ */
}

void solve_quadratic(const double a, const double b, const double c) {
    double discriminant = calculate_discriminant(a, b, c);
    cout << "Discriminant = " << discriminant << endl;
    
    if (discriminant > 0) {
        double sqrt_of_d = sqrt(discriminant);
        double x1 = (-b + sqrt_of_d) / (2 * a);
        double x2 = (-b - sqrt_of_d) / (2 * a);
        
        cout << "Discriminant > 0 => The equation has 2 roots:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        
        check_real_roots(a, b, c, x1, x2);
        
    } else if (discriminant == 0) {
        cout << "Discriminant = 0 => The equation has 1 root:" << endl;
        double x = -b / (2 * a);
        cout << "x = " << x << endl;
        
        check_single_root(a, b, c, x);
        
    } else {
        cout << "Discriminant < 0 => The equation has complex roots:" << endl;
        double re = -b / (2 * a);
        double im = sqrt(-discriminant) / (2 * a);
        cout << "x₁ = " << re << " + " << im << "i" << endl;
        cout << "x₂ = " << re << " - " << im << "i" << endl;
        
        check_complex_roots(a, b, c, re, im);
    }
}

void solve_equation(double a, double b, double c) {
    print_equation(a, b, c);
    
    if (a == 0) {
        solve_linear(b, c);
    } else {
        solve_quadratic(a, b, c);
    }
}