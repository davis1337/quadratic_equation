#include "equation.h"

Equation::Equation() : a(0), b(0), c(0) {};

Equation::Equation(const double a, const double b, const double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    if (are_bad_coeffs) {
        throw invalid_argument("Error with arguments\nPlease try again...");
    }
}

Equation::~Equation() = default;

void Equation::input_сoeffs() {
    cout << "Enter coefficents of the quadratic equation (a, b, c)" << endl;
    cout << "Enter a: ";
    cin >> a;
    if (cin.fail() || are_bad_coeffs()) {
        throw invalid_argument("You should have entered a normal NUMBER!");
    }
    cout << "Enter b: ";
    cin >> b;
    if (cin.fail() || are_bad_coeffs()) {
        throw invalid_argument("You should have entered a normal NUMBER!");
    }
    cin >> c;
    if (cin.fail() || are_bad_coeffs()) {
        throw invalid_argument("You should have entered a normal NUMBER!");
    }
}

double Equation::discriminant() const {
    return pow(b, 2) - (4 * a * c);
}

bool Equation::are_bad_coeffs() const {
    if (isnan(a) || isnan(b) || isnan(c) || isinf(a) || isinf(b) || isinf(c)) {
        return true;
    }
    return false;
}

void Equation::solving_without_a() const {
    if (b == 0) {
        if (c == 0) {
            cout << "The equation has an infinite number of solutions (0 = 0)" << endl;
        } else {
            cout << "The equation dont have solutions (" << c << " = 0" << endl;
        }
    } else {
        solving_linear();
    }
}

void Equation::solving_linear() const {
    cout << "This is the linear equation (a = 0)" << endl;
    double x = (double)-c/b;
    cout << "x = " << x << endl;
}

void Equation::solving_default() const {
    double discriminant_value = discriminant();
    cout << "Discriminant = " << discriminant_value << endl;
    if (discriminant_value > 0) {
        double x1 = 0., x2 = 0.;
        x1 = (-b + sqrt(discriminant_value)) / (2 * a);
        x2 = (-b - sqrt(discriminant_value)) / (2 * a);
        cout << "Discriminant > 0 => The equation has 2 roots" << endl;
        check_roots_default(x1, x2);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        
    } else {
        if (discriminant_value == 0) {
            cout << "Discriminant = 0 => The equation has 1 root" << endl;
            double x = -b / (2 * a);
            check_roots_one(x);
            cout << "x = " << x << endl;
        } else {
            solving_complex();
        }
    }
}

void Equation::check_roots_default(const double x1, const double x2) const {
    double temp_equation = a * pow(x1, 2) + b * x1 + c;
    double temp_equation2 = a * pow(x2, 2) + b * x2 + c;
    if (temp_equation != 0) {
        cout << "______Unsuccess (x1)" << endl;
        throw invalid_argument("ERROR WITH MY PROGRAM BRUH");
    }
    if (temp_equation2 != 0) {
        cout << "______Unsuccess (x2)" << endl;
        throw invalid_argument("ERROR WITH MY PROGRAM BRUH");
    }
}

void Equation::check_roots_one(const double x) const {
    double temp_equation = a * pow(x, 2) + b * x + c;
    if (temp_equation != 0) {
        cout << "_______Unsuccess" << endl;
        throw invalid_argument("ERROR WITH MY PROGRAM BRUH");
    }
}

void Equation::solving_complex() const {
    cout << "Discriminant = 0 => The equation has complex roots" << endl;
    double discriminant_value = discriminant();
    double re = -b / (2 * a);
    double im = sqrt(-discriminant_value) / (2 * a);
    cout << "x1 = " << re << " + " << im << "i" << endl;
    cout << "x2 = " << re << " - " << im << "i" << endl;


    /* НУЖНО ДОБАВИТЬ ФУНКЦИЮ ПРОВЕРКИ КОМПЛ КОРНЕЙ */

}