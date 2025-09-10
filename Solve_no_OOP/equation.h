#pragma once

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;


struct Coefficients {
    double a, b, c;
};


Coefficients input_coefficients();
double calculate_discriminant(const double a, const double b, const double c);
bool are_bad_coefficients(const double a, const double b, const double c);
void solve_equation(const double a, const double b, const double c);
void solve_linear(const double b, const double c);
void solve_quadratic(const double a, const double b, const double c);
void print_equation(const double a, const double b, const double c);
void check_real_roots(const double a, const double b, const double c, double x1, double x2);
void check_single_root(const double a, const double b, const double c, double x);
void check_complex_roots(const double a, const double b, const double c, double re, double im);