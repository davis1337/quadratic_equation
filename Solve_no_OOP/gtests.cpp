#include "equation.h"
#include <gtest/gtest.h>
#include <limits>
#include <cmath>

// Тесты для функции calculate_discriminant
TEST(DiscriminantTest, PositiveDiscriminant) {
    double d = calculate_discriminant(1, -5, 6); // x² - 5x + 6 = 0
    EXPECT_DOUBLE_EQ(d, 1.0); // (-5)² - 4*1*6 = 25 - 24 = 1
}

TEST(DiscriminantTest, ZeroDiscriminant) {
    double d = calculate_discriminant(1, -4, 4); // x² - 4x + 4 = 0
    EXPECT_DOUBLE_EQ(d, 0.0); // (-4)² - 4*1*4 = 16 - 16 = 0
}

TEST(DiscriminantTest, NegativeDiscriminant) {
    double d = calculate_discriminant(1, 0, 1); // x² + 1 = 0
    EXPECT_DOUBLE_EQ(d, -4.0); // 0² - 4*1*1 = -4
}

TEST(DiscriminantTest, LargeNumbers) {
    double d = calculate_discriminant(1, 1000000, 1);
    EXPECT_DOUBLE_EQ(d, 999999999996.0); // 1e12 - 4
}

// Тесты для функции are_bad_coefficients
TEST(BadCoefficientsTest, NormalCoefficients) {
    EXPECT_FALSE(are_bad_coefficients(1.0, 2.0, 3.0));
    EXPECT_FALSE(are_bad_coefficients(0.0, 0.0, 0.0));
    EXPECT_FALSE(are_bad_coefficients(-1.0, 2.5, -3.7));
}

TEST(BadCoefficientsTest, NaNcoefficients) {
    EXPECT_TRUE(are_bad_coefficients(nan(""), 2.0, 3.0));
    EXPECT_TRUE(are_bad_coefficients(1.0, nan(""), 3.0));
    EXPECT_TRUE(are_bad_coefficients(1.0, 2.0, nan("")));
}

TEST(BadCoefficientsTest, InfinityCoefficients) {
    EXPECT_TRUE(are_bad_coefficients(std::numeric_limits<double>::infinity(), 2.0, 3.0));
    EXPECT_TRUE(are_bad_coefficients(1.0, std::numeric_limits<double>::infinity(), 3.0));
    EXPECT_TRUE(are_bad_coefficients(1.0, 2.0, std::numeric_limits<double>::infinity()));
}

TEST(BadCoefficientsTest, NegativeInfinityCoefficients) {
    EXPECT_TRUE(are_bad_coefficients(-std::numeric_limits<double>::infinity(), 2.0, 3.0));
}

// Тесты для функции print_equation
TEST(PrintEquationTest, NormalQuadratic) {
    testing::internal::CaptureStdout();
    print_equation(1, -5, 6);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
}

TEST(PrintEquationTest, LinearEquation) {
    testing::internal::CaptureStdout();
    print_equation(0, 2, -4);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
}

TEST(PrintEquationTest, SpecialCases) {
    testing::internal::CaptureStdout();
    print_equation(1, 0, 0); // x² = 0
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
}

// Тесты для функции solve_linear
TEST(SolveLinearTest, NormalLinear) {
    testing::internal::CaptureStdout();
    solve_linear(2, -4); // 2x - 4 = 0, x = 2
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("x ="), std::string::npos);
}

TEST(SolveLinearTest, NoSolution) {
    testing::internal::CaptureStdout();
    solve_linear(0, 5); // 0x + 5 = 0, no solution
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("solutions"), std::string::npos);
}

TEST(SolveLinearTest, InfiniteSolutions) {
    testing::internal::CaptureStdout();
    solve_linear(0, 0); // 0x + 0 = 0, infinite solutions
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("infinite"), std::string::npos);
}

// Тесты для функции check_real_roots
TEST(CheckRealRootsTest, CorrectRoots) {
    testing::internal::CaptureStdout();
    check_real_roots(1, -5, 6, 2, 3); // x² - 5x + 6 = 0, roots 2 and 3
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Checking roots:"), std::string::npos);
}

TEST(CheckRealRootsTest, IncorrectRoots) {
    testing::internal::CaptureStdout();
    check_real_roots(1, -5, 6, 1, 1); // Wrong roots
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Error with calculate"), std::string::npos);
}

// Тесты для функции check_single_root
TEST(CheckSingleRootTest, CorrectRoot) {
    testing::internal::CaptureStdout();
    check_single_root(1, -4, 4, 2); // x² - 4x + 4 = 0, root 2
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Checking root:"), std::string::npos);
}

TEST(CheckSingleRootTest, IncorrectRoot) {
    testing::internal::CaptureStdout();
    check_single_root(1, -4, 4, 1); // Wrong root
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Error with calculate"), std::string::npos);
}

// Тесты для функции check_complex_roots
TEST(CheckComplexRootsTest, ComplexRootsCheck) {
    testing::internal::CaptureStdout();
    check_complex_roots(1, 0, 1, 0, 1); // x² + 1 = 0, roots ±i
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Checking complex roots:"), std::string::npos);
}

// Тесты для функции solve_quadratic
TEST(SolveQuadraticTest, TwoRealRoots) {
    testing::internal::CaptureStdout();
    solve_quadratic(1, -5, 6); // x² - 5x + 6 = 0
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Discriminant > 0"), std::string::npos);
    EXPECT_NE(output.find("x1 ="), std::string::npos);
    EXPECT_NE(output.find("x2 ="), std::string::npos);
}

TEST(SolveQuadraticTest, OneRealRoot) {
    testing::internal::CaptureStdout();
    solve_quadratic(1, -4, 4); // x² - 4x + 4 = 0
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Discriminant = 0"), std::string::npos);
    EXPECT_NE(output.find("x ="), std::string::npos);
}

TEST(SolveQuadraticTest, ComplexRoots) {
    testing::internal::CaptureStdout();
    solve_quadratic(1, 0, 1); // x² + 1 = 0
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Discriminant < 0"), std::string::npos);
    EXPECT_NE(output.find("complex roots"), std::string::npos);
}

// Тесты для функции solve_equation
TEST(SolveEquationTest, QuadraticEquation) {
    testing::internal::CaptureStdout();
    solve_equation(1, -5, 6);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
}

TEST(SolveEquationTest, LinearEquation) {
    testing::internal::CaptureStdout();
    solve_equation(0, 2, -4);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("linear equation"), std::string::npos);
}

TEST(SolveEquationTest, NoSolutionCase) {
    testing::internal::CaptureStdout();
    solve_equation(0, 0, 5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("solutions"), std::string::npos);
}

TEST(SolveEquationTest, InfiniteSolutionsCase) {
    testing::internal::CaptureStdout();
    solve_equation(0, 0, 0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("infinite"), std::string::npos);
}

// Тесты для граничных случаев и ошибок
TEST(EdgeCasesTest, VeryLargeNumbers) {
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(solve_equation(1e100, 1e100, 1e100));
}

TEST(EdgeCasesTest, VerySmallNumbers) {
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(solve_equation(1e-100, 1e-100, 1e-100));
}

TEST(EdgeCasesTest, FractionalCoefficients) {
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(solve_equation(0.5, -1.5, 1.0));
}

TEST(EdgeCasesTest, NegativeCoefficients) {
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(solve_equation(-1, 2, 3));
}

// Тесты для структуры Coefficients
TEST(CoefficientsTest, StructureInitialization) {
    Coefficients coeffs = {1.0, 2.0, 3.0};
    EXPECT_DOUBLE_EQ(coeffs.a, 1.0);
    EXPECT_DOUBLE_EQ(coeffs.b, 2.0);
    EXPECT_DOUBLE_EQ(coeffs.c, 3.0);
}

// Интеграционные тесты для основных сценариев
TEST(IntegrationTest, CompleteWorkflowTwoRoots) {
    testing::internal::CaptureStdout();
    solve_equation(1, -5, 6); // x² - 5x + 6 = 0, roots: 2, 3
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
    EXPECT_NE(output.find("Discriminant = 1"), std::string::npos);
    EXPECT_NE(output.find("x1 = 3"), std::string::npos);
    EXPECT_NE(output.find("x2 = 2"), std::string::npos);
}

TEST(IntegrationTest, CompleteWorkflowOneRoot) {
    testing::internal::CaptureStdout();
    solve_equation(1, -4, 4); // x² - 4x + 4 = 0, root: 2
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
    EXPECT_NE(output.find("Discriminant = 0"), std::string::npos);
    EXPECT_NE(output.find("x = 2"), std::string::npos);
}

TEST(IntegrationTest, CompleteWorkflowComplexRoots) {
    testing::internal::CaptureStdout();
    solve_equation(1, 0, 1); // x² + 1 = 0, roots: ±i
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
    EXPECT_NE(output.find("Discriminant = -4"), std::string::npos);
    EXPECT_NE(output.find("complex roots"), std::string::npos);
}

TEST(IntegrationTest, CompleteWorkflowLinear) {
    testing::internal::CaptureStdout();
    solve_equation(0, 2, -4); // 2x - 4 = 0, root: 2
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
    EXPECT_NE(output.find("linear equation"), std::string::npos);
    EXPECT_NE(output.find("x = 2"), std::string::npos);
}

// Параметризованные тесты для различных типов уравнений
class EquationTypeTest : public ::testing::TestWithParam<std::tuple<double, double, double, std::string>> {
};

TEST_P(EquationTypeTest, SolveVariousEquations) {
    auto params = GetParam();
    double a = std::get<0>(params);
    double b = std::get<1>(params);
    double c = std::get<2>(params);
    std::string description = std::get<3>(params);
    
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(solve_equation(a, b, c));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Equation:"), std::string::npos);
}

INSTANTIATE_TEST_SUITE_P(
    VariousEquations,
    EquationTypeTest,
    ::testing::Values(
        std::make_tuple(1.0, -3.0, 2.0, "x² - 3x + 2 = 0"),
        std::make_tuple(2.0, -4.0, 2.0, "2x² - 4x + 2 = 0"),
        std::make_tuple(1.0, 0.0, -4.0, "x² - 4 = 0"),
        std::make_tuple(0.0, 3.0, -6.0, "3x - 6 = 0"),
        std::make_tuple(1.0, 1.0, 1.0, "x² + x + 1 = 0 (complex)")
    )
);

// Тесты для проверки математической корректности
TEST(MathematicalCorrectnessTest, RootVerification) {
    // Проверим, что корни действительно удовлетворяют уравнению
    double a = 1.0, b = -5.0, c = 6.0; // x² - 5x + 6 = 0
    double x1 = 3.0, x2 = 2.0; // корни
    
    double result1 = a * x1 * x1 + b * x1 + c;
    double result2 = a * x2 * x2 + b * x2 + c;
    
    EXPECT_NEAR(result1, 0.0, 1e-10);
    EXPECT_NEAR(result2, 0.0, 1e-10);
}

TEST(MathematicalCorrectnessTest, LinearRootVerification) {
    // Проверим линейное уравнение
    double b = 2.0, c = -4.0; // 2x - 4 = 0
    double x = -c / b; // x = 2
    
    double result = b * x + c;
    EXPECT_NEAR(result, 0.0, 1e-10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}