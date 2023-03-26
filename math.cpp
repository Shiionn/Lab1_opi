#include cmath
#include iostream

функция для подсчета уравнения
double F(double x) {
    return 0.2  x - (cos(3  x)  cos(3  x));
}

поиск корня
double FindRoot(double (f)(double), double a, double b, double eps) {
    double m;
    while ((b - a)  2  eps) {
        m = (a + b)  2;
        if ((f(a)  f(m))  0) a = m;
        else b = m;
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, Russian);
    ввод интервала и погрешности
    double a, b, eps, x;
    stdcout  Введите интервалn;
    stdcout  a= ;
    stdcin  a;
    stdcout  b= ;
    stdcin  b;
    проверяем корректность интервала
    if (F(a)  F(b)  0) {
        stdcout  Не верный интервал!n;
        return 0;
    }
    stdcout  Погрешность;
    stdcin  eps;
    поиск корня
    x = FindRoot(F, a, b, eps);
    stdcout  x =   x;
    return 0;
}
