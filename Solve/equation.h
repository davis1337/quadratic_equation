#pragma once

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class Equation {
    public:
        Equation();
        Equation(const double a, const double b, const double c);
        ~Equation();
        void solving_equation() const;
        void input_сoeffs();
    private:
        double a, b, c;
        double discriminant() const;
        //void set_сoeffs(const double a, const double b, const double c);
        bool are_bad_coeffs() const; 
        void solving_without_a() const;
        void solving_complex() const;
        void solving_linear() const;
        void solving_default() const;
        void check_roots_default(const double x1, const double x2) const;
        void check_roots_one(const double x) const;
        void check_roots_complex(const double re, const double im) const;
        void print_equation() const;
};