#include <cmath>
#include <iostream>

//функция для подсчета уравнения
double F(double x) {
    return 0.2 * x - (cos(3 * x) * cos(3 * x));
}

//поиск корня
double FindRoot(double (*f)(double), double a, double b, double eps) {
    double c;
    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if ((f(a) * f(c)) > 0) a = c;
        else b = c;
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //ввод интервала и погрешности
    double a, b, eps, x;
    std::cout << "Введите интервал:\n";
    std::cout << "a= ";
    std::cin >> a;
    std::cout << "b= ";
    std::cin >> b;
    //проверяем корректность интервала
    if (F(a) * F(b) > 0) {
        std::cout << "Не верный интервал!\n";
        return 0;
    }
    std::cout << "Погрешность:";
    std::cin >> eps;
    //поиск корня
    x = FindRoot(F, a, b, eps);
    std::cout << "x = " << x;
    return 0;
}

