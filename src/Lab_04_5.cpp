// Джамалов Олександр Олегович, РІ-11
// Завдання 04.5, варіант 7
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

#include <random>

bool hit(long double x, long double y, long double r)
{
    long double u = x / r, v = y / r;
    bool circle = hypot(u + 1, v - 1) <= 1;
    bool rectangle = u >= 0 && u <= 2 && v >= -1 && v <= 0;
    return circle || rectangle;
}

void printPoint(int n, long double x, long double y, long double r)
{
    cout << setw(4) << n << setw(16) << x << setw(16) << y
         << setw(8) << (hit(x, y, r) ? "yes" : "no") << '\n';
}

int main()
{
    long double r, x, y;
    cout << "R = ";
    if (!(cin >> r) || !isfinite(r) || r <= 0
        || r > numeric_limits<long double>::max() / 2)
    {
        cerr << "R must be finite and positive\n";
        return 1;
    }
    cout << fixed << setprecision(8);
    cout << "Manual points: enter 10 pairs x y\n";
    cout << setw(4) << "n" << setw(16) << "x"
         << setw(16) << "y" << setw(8) << "hit" << '\n';
    for (int i = 1; i <= 10; ++i)
    {
        if (!(cin >> x >> y) || !isfinite(x) || !isfinite(y))
        {
            cerr << "Invalid coordinates\n";
            return 1;
        }
        printPoint(i, x, y, r);
    }
    // Фіксоване зерно дає відтворювані псевдовипадкові точки.
    mt19937 generator(7);
    uniform_real_distribution<long double> coordinate(-2 * r, 2 * r);
    cout << "Random points, x and y in [-2R, 2R]\n";
    cout << setw(4) << "n" << setw(16) << "x"
         << setw(16) << "y" << setw(8) << "hit" << '\n';
    for (int i = 1; i <= 10; ++i)
    {
        x = coordinate(generator);
        y = coordinate(generator);
        printPoint(i, x, y, r);
    }
    return 0;
}
