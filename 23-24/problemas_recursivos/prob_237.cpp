#include <iostream>

using namespace std;

// Problema 237 - Polidivisibles
// Resuelto en la funcion polidivisible(long long n, bool polidiv, int length)

/* Pre : { 0 <= n <= 10^18 } */
bool polidivisible(long long n, bool polidiv, int length)
{
    if (n < 10)
        return polidiv;
    else
    {
        if (n % length != 0)
            polidiv = false;
            
        return polidivisible(n / 10, polidiv, length - 1);
    }
}
/* 
    Complejidad
    Disminucion del tam del problema por division

    - a = 1
    - b = 10
    - k = 0

    T(n) = O(n^k * log n) = O(log n)
*/

/*  Post : { ret = true sii n es polidivisible } */

int main(int argc, char const *argv[])
{
    long long n;
    int length;
    bool polidiv = true;
    while ((cin >> n) && n)
    {
        length = to_string(n).length();
        if (polidivisible(n, polidiv, length))
            cout << "POLIDIVISIBLE" << '\n';
        else
            cout << "NO POLIDIVISIBLE" << '\n';
    }
    return 0;
}
