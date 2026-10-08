// Джамалов Олександр Олегович, РІ-11
// Завдання 04.6, варіант 7
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    long double p1 = 1, p2 = 1, p3 = 1, p4 = 1;
    int k = 1;
    while (k <= 20)
    {
        long double sumSquares = 0, sumDenominator = 0;
        int i = 1;
        while (i <= k)
        {
            sumSquares += i * i;
            sumDenominator += i * i;
            ++i;
        }
        p1 *= sumSquares / (1 + sumDenominator);
        ++k;
    }
    k = 1;
    do
    {
        long double sumSquares = 0, sumDenominator = 0;
        int i = 1;
        do
        {
            sumSquares += i * i;
            sumDenominator += i * i;
            ++i;
        } while (i <= k);
        p2 *= sumSquares / (1 + sumDenominator);
        ++k;
    } while (k <= 20);
    for (k = 1; k <= 20; ++k)
    {
        long double sumSquares = 0, sumDenominator = 0;
        for (int i = 1; i <= k; ++i)
        {
            sumSquares += i * i;
            sumDenominator += i * i;
        }
        p3 *= sumSquares / (1 + sumDenominator);
    }
    for (k = 20; k >= 1; --k)
    {
        long double sumSquares = 0, sumDenominator = 0;
        for (int i = k; i >= 1; --i)
        {
            sumSquares += i * i;
            sumDenominator += i * i;
        }
        p4 *= sumSquares / (1 + sumDenominator);
    }
    cout << scientific << setprecision(12);
    cout << "while:     " << p1 << '\n';
    cout << "do-while:  " << p2 << '\n';
    cout << "for++:     " << p3 << '\n';
    cout << "for--:     " << p4 << '\n';
    return 0;
}
