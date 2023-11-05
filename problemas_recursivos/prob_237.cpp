#include <iostream>

using namespace std;

// Problema 237 - Polidivisibles
// Resuelto en la funcion polidivisible(long long n, bool polidiv, int length)

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
