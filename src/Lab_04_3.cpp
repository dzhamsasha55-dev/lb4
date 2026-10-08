// Джамалов Олександр Олегович, РІ-11
// Завдання 04.3, варіант 7
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

bool value(long double a, long double b, long double c,
           long double x, long double& f)
{
    if (x < 5 && c != 0)
        f = -a * x * x - b;
    else if (x > 5 && c == 0)
        f = (x - a) / x;
    else
    {
        if (c == 0) return false;
        f = -x / c;
    }
    return isfinite(f);
}

int main()
{
    long double a, b, c, xp, xk, dx;
    long long last;
    cout << "a b c = ";
    if (!(cin >> a >> b >> c) || !isfinite(a)
        || !isfinite(b) || !isfinite(c)
        || !readGrid(xp, xk, dx, last))
    {
        cerr << "Invalid input\n";
        return 1;
    }
    cout << "Task 04.3, variant 7\n";
    cout << setw(14) << "x" << setw(20) << "F" << '\n';
    cout << fixed << setprecision(10);
    for (long long i = 0; i <= last; ++i)
    {
        long double x = xp + i * dx, f = 0;
        cout << setw(14) << x;
        if (value(a, b, c, x, f)) cout << setw(20) << f;
        else cout << setw(20) << "undefined";
        cout << '\n';
    }
    return 0;
}
