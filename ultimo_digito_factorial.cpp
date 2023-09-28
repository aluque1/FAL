#include <iostream>

using namespace std;

// Ejercicio 114 ultimo digito factorial
// Resuelto en la funcion ultimo_digito_factorial(int n)

int ultimo_digito_factorial(int n)
{
    
    
    // TLE
    /* int ret = 1;
    for (int i = 2; i <= n; ++i)
    {
        ret = (ret * i) % 10;
    }
    return ret; */
}

bool resuelve()
{
    // 1. Lectura
    int n, fact;
    cin >> n;
    

    for (int i = 0; i < n; i++)
    {
        cin >> fact;
        // 2. Calculo
        int ret = ultimo_digito_factorial(fact);

        // 3. Escribir el resultado
        cout << ret << endl;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    while (resuelve())
    {
        ;
    }
    return 0;
}