
#include <iostream>

using namespace std;

// Ejercicio 242 Erasmus
// Resuelto en la funcion erasmus(int v[], int n)

int v[100000]; // para FAL declaramos el vector como variable global para que no de error de compilacion por exceso de memoria

long long erasmus(int n, int v[])
{
    long long ret;
    int i = 0;
    long long sumaAcu = 0; // usamos una variable acumuladora porque guardamos la suma

    while (i < n)
    {
        // ret = Sum j, k : 0 <= j < k < i : v[j] * v[k]
        // sumaAcu = Sum j : 0 <= j < i : v[j]

        ret += sumaAcu * v[i];
        sumaAcu += v[i];
        ++i;   

        // ret = Sum j, k : 0 <= j < k < i : v[j] * v[k]
        // sumaAcu = Sum j : 0 <= j < i : v[j]    
    }
    
    return ret;
}

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
    long long ret = erasmus(n, v);

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
