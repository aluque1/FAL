#include <iostream>

using namespace std;

// problema 237 Polidivisibles
// resuelto en la funcion polidivisible(int n)

/**
 * Un num es polidivisible, si es divisible por su longitud, se divide por 10 y siguie siendo polidivisible por su longitud
 */
bool polidivisible(int n, bool polidiv)
{
    
}

int main(int argc, char const *argv[])
{
    int n;
    bool polidiv = true;
    while ((cin >> n) && n)
    {
        if (polidivisible(n, polidiv))
            cout << "POLIDIVISIBLE" << '\n';
        else
            cout << "NO POLIDIVISIBLE" << '\n';
    }
    return 0;
}
