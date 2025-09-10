#pragma once

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/**
 * @brief Структура, которая будет хранить наши коэффиценты
 */
struct Coefficients {
    double a, b, c;
};

/**
 * @brief для ввода коэффицентов уравнения
 * @return структуру с введенными коэффицентами
 */
Coefficients input_coefficients();

/**
 * @brief считает дискриминант уравнения
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 * @return рассчитанный дискриминант
 */
double calculate_discriminant(const double a, const double b, const double c);

/**
 * @brief проверяет коэффиценты на бесконечность (inf) и на то, что это число (NaN)
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 * @return true - если есть inf или NaN , false - если их нет (коэффиценты нормальные числа)
 */
bool are_bad_coefficients(const double a, const double b, const double c);

/**
 * @brief главная функция, которая решает наше уравнение с помощью вызова нужных второстеп. ф-ий
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 */
void solve_equation(const double a, const double b, const double c);

/**
 * @brief решает линейное уравнение
 * @param b коэффицент при x
 * @param c свободный коэффицент
 */
void solve_linear(const double b, const double c);

/**
 * @brief решает стандартное квадратное уравнение
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 */
void solve_quadratic(const double a, const double b, const double c);

/**
 * @brief печатает наше уравнение
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 */
void print_equation(const double a, const double b, const double c);

/**
 * @brief проверяет 2 корня уравнения
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 * @param x1 первый корень
 * @param x2 второй корень
 */
void check_real_roots(const double a, const double b, const double c, double x1, double x2);

/**
 * @brief проверяет 1 корень уравнения
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 * @param x корень уравнения
 */
void check_single_root(const double a, const double b, const double c, double x);

/**
 * @brief проверяет комплексные корни уравнения
 * @param a коэффицент при x^2
 * @param b коэффицент при x
 * @param c свободный коэффицент
 * @param re действительная часть комплексного числа
 * @param im мнимая часть комплексного числа
 */
void check_complex_roots(const double a, const double b, const double c, double re, double im);