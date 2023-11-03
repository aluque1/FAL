     #include <iostream>

using namespace std;

// problema 237 Polidivisibles
// resuelto en la funcion polidivisible(int n)

/**
 * Un num es polidivisible, si es divisible por su longitud, se divide por 10 y siguie siendo polidivisible por su longitud
 */
bool polidivisible(int n, bool polidiv)
{
    if(n < 10)
        return polidiv;
    else
    {
        if (n % to_string(n).length() != 0)
            polidiv = false;
            
        return polidivisible(n / 10, polidiv);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    bool polidiv = true;
    while ((cin >> n))
    {
        if (polidivisible(n, polidiv))
            cout << "POLIDIVISIBLE" << '\n';
        else
            cout << "NO POLIDIVISIBLE" << '\n';
    }
    return 0;
}
