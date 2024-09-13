#include <iostream>

using namespace std;

// Problema 347 - Haciendo pajaritas de papel
// Resuelto en la funcion pajaritas(int ancho, int alto)
long long pajaritas(long long ancho, long long alto) // TLE -------------
{
    long long total = 0;
    long long minimum = 0;
    long long maximum = 0;
    if (ancho < 10 || alto < 10)
        return total;
    else
    {
        ++total;
        minimum = min(ancho, alto);
        maximum = max(ancho, alto);
        total += pajaritas(minimum, maximum - minimum);
    }
    return total;
}

int main()
{
    long long ancho, alto;
    while ((cin >> ancho >> alto) && alto && ancho)
    {
        cout << pajaritas(ancho, alto) << endl;
    }
    return 0;
}