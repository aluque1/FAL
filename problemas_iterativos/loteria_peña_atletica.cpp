#include <iostream>

using namespace std;

// Ejercicio 219 Erasmus
// Resuelto en la funcion erasmus(int v[], int n)

int v[100000]; 

// { Pre: 0 <= n <= longitud(v) }
long loteria_atlelitca(int v[], int n) /* return ret */
{
    long ret = 0;
    int i = 0;
    while (i < n)
    {
        if (v[i] % 2 == 0)
        {
            ++ret;
        }
        ++i;
    }
    return ret;
}
// { Post: ret = #i : 0 <= i < n ; v[i] % 2 = 0}

bool resuelve()
{
    // 1. Lectura
    int n;
    cin >> n;
    if (n == 0)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 2. Calculo
    long long ret = loteria_atlelitca(v, n);

    // 3. Escribir el resultado
    cout << ret << endl;
    return true;
}

int main(int argc, char const *argv[])
{
    while (resuelve())
    {
        ;
    }

    return 0;
}
