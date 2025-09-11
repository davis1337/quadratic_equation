CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = quadratic_solver
TEST_TARGET = quadratic_tests

all: $(TARGET)

# Основная программа
$(TARGET): main.cpp equation.cpp equation.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp equation.cpp

# Тесты
test: main_test.cpp equation.cpp equation.h
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) main_test.cpp equation.cpp

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Запуск тестов
run-test: test
	./$(TEST_TARGET)

# Очистка
clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all run run-test clean