// Джамалов Олександр Олегович, РІ-11
// Завдання 04.1, варіант 7
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    long long N;
    cout << "N = ";
    if (!(cin >> N) || N < 1 || N > 1000000)
    {
        cerr << "Invalid N\n";
        return 1;
    }
    long double s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    long long k = 1;
    while (k <= N)
    {
        long double d = 2.0L * k + 1;
        s1 += 1 / (d * d);
        ++k;
    }
    k = 1;
    do
    {
        long double d = 2.0L * k + 1;
        s2 += 1 / (d * d);
        ++k;
    } while (k <= N);
    for (k = 1; k <= N; ++k)
    {
        long double d = 2.0L * k + 1;
        s3 += 1 / (d * d);
    }
    for (k = N; k >= 1; --k)
    {
        long double d = 2.0L * k + 1;
        s4 += 1 / (d * d);
    }
    cout << fixed << setprecision(12);
    cout << "while:     " << s1 << '\n';
    cout << "do-while:  " << s2 << '\n';
    cout << "for++:     " << s3 << '\n';
    cout << "for--:     " << s4 << '\n';
    return 0;
}
