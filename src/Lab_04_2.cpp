// Джамалов Олександр Олегович, РІ-11
// Завдання 04.2, варіант 7
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

// Кількість вузлів сітки; x обчислюється через номер вузла.
bool readGrid(long double& xp, long double& xk,
              long double& dx, long long& last)
{
    cout << "xp xk dx = ";
    if (!(cin >> xp >> xk >> dx) || !isfinite(xp)
        || !isfinite(xk) || !isfinite(dx) || dx == 0
        || (xp < xk && dx < 0) || (xp > xk && dx > 0))
        return false;
    long double q = (xk - xp) / dx;
    if (!isfinite(q) || q > 100000)
        return false;
    long double tol = 64 * numeric_limits<long double>::epsilon()
                      * max(1.0L, abs(q));
    last = static_cast<long long>(floor(q + tol));
    return true;
}

long double value(long double x)
{
    long double g;
    if (x <= -5)
        g = atan(exp(x));
    else if (x <= 0)
        g = 1 + x * x * x / 4;
    else
        g = log(abs(x)) - x / 5;
    return x * x * sin(x / 2) + g;
}

int main()
{
    long double xp, xk, dx;
    long long last;
    if (!readGrid(xp, xk, dx, last))
    {
        cerr << "Invalid interval or step\n";
        return 1;
    }
    cout << "Task 04.2, variant 7\n";
    cout << setw(14) << "x" << setw(20) << "y" << '\n';
    cout << fixed << setprecision(10);
    long long i = 0;
    while (i <= last)
    {
        long double x = xp + i * dx;
        long double y = value(x);
        cout << setw(14) << x;
        if (isfinite(y)) cout << setw(20) << y;
        else cout << setw(20) << "undefined";
        cout << '\n';
        ++i;
    }
    return 0;
}
