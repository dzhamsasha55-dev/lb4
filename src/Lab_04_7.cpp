// Джамалов Олександр Олегович, РІ-11
// Завдання 04.7, варіант 7
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

bool series(long double x, long double eps,
            long double& sum, long long& terms)
{
    long double a = -x;
    sum = acos(-1.0L) / 2;
    terms = 0;
    long long n = 0;
    do
    {
        sum += a;
        ++terms;
        ++n;
        // a_n / a_(n-1) = -x*x*(2*n-1)/(2*n+1).
        a *= -x * x * (2.0L * n - 1) / (2.0L * n + 1);
        if (!isfinite(sum) || terms >= 10000000) return false;
    } while (abs(a) >= eps);
    return true;
}

int main()
{
    long double xp, xk, dx, eps;
    long long last;
    if (!readGrid(xp, xk, dx, last))
    {
        cerr << "Invalid interval or step\n";
        return 1;
    }
    cout << "eps = ";
    if (!(cin >> eps) || !isfinite(eps) || eps <= 0
        || min(xp, xk) < -1 || max(xp, xk) > 1)
    {
        cerr << "Require eps > 0 and -1 <= x <= 1\n";
        return 1;
    }
    cout << "Task 04.7, variant 7\n";
    cout << setw(12) << "x" << setw(18) << "arcctg(x)"
         << setw(18) << "S" << setw(12) << "terms" << '\n';
    cout << fixed << setprecision(10);
    long long i = 0;
    while (i <= last)
    {
        long double x = xp + i * dx, sum;
        long long terms;
        cout << setw(12) << x << setw(18) << atan2(1.0L, x);
        if (series(x, eps, sum, terms))
            cout << setw(18) << sum << setw(12) << terms;
        else
            cout << setw(18) << "no convergence" << setw(12) << terms;
        cout << '\n';
        ++i;
    }
    return 0;
}
