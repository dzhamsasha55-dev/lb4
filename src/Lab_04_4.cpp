// Джамалов Олександр Олегович, РІ-11
// Завдання 04.4, варіант 7
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

long double value(long double x, long double r)
{
    if (x < -r) return r;
    if (x <= r)
    {
        long double t = x / r;
        long double root = sqrt(max(0.0L, 1 - t * t));
        // Стійкий запис r - sqrt(r*r - x*x).
        return r * t * t / (1 + root);
    }
    if (x <= 6)
        return r - (r + 3) * (x - r) / (6 - r);
    return x - 9;
}

int main()
{
    long double r, xp, xk, dx;
    long long last;
    cout << "R = ";
    if (!(cin >> r) || !isfinite(r) || r <= 0 || r >= 6
        || !readGrid(xp, xk, dx, last))
    {
        cerr << "Require 0 < R < 6 and a valid interval\n";
        return 1;
    }
    cout << "Task 04.4, variant 7\n";
    cout << setw(14) << "x" << setw(20) << "y" << '\n';
    cout << fixed << setprecision(10);
    for (long long i = 0; i <= last; ++i)
    {
        long double x = xp + i * dx;
        cout << setw(14) << x << setw(20) << value(x, r) << '\n';
    }
    return 0;
}
