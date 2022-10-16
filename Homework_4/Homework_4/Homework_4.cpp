    //Разработать класс многочленов(для хранения коэффициентов можно использовать std::vector<> или встроенный массив фиксированного размера).Методы для вычисления
    //значения многочлена для заданного аргумента, для сложения, вычитания и умножения многочленов

    // 1+2*x-3*x^2
#include <iostream>
#include <vector>
#include <fstream>
#include "Polynom.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<double> coef1{ 1,2,3 };
    std::vector<double> coef2{ 3,-6,9, 7};

    Polynom test1( coef1.size()-1, coef1);
    Polynom test2(coef2.size() - 1, coef2);

    std::cout << "Polynom 1 : " << test1 << std::endl;
    std::cout << "Polynom 2 : " << test2 << std::endl;
    std::cout << "Polynom 1 result: " << test1.result(1) << std::endl;
    std::cout << "Polynom 2 result: " << test2.result(1) << std::endl;
    Polynom test3 = test1 + test2;
    std::cout << "Polynom sum result: " << test3 << std::endl;
    Polynom test4 = test1 - test2;
    std::cout << "Polynom sub result: " << test4 << std::endl;
    Polynom test5 = test1 * test2;
    std::cout << "Polynom multi result: " << test5 << std::endl;

    try {
        std::vector<double> coef3(-2);
        Polynom test6(coef3.size() - 1, coef3);
        std::cout << test6 << '\n';
    }
    catch (const std::logic_error& err) {
        std::cerr << "Polynom can't created because of " << err.what() << '\n';
    }
    return 0;
}

