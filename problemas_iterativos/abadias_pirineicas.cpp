#include <iostream>

using namespace std;

// Ejercicio 171 Abadias pirineicas
// Resuleto en la funcion abadias_pirineicas(int n, int v[])

int v[100000];

/*
    Contador
*/
int abadias_pirineicas(int n, int v[])
{
    
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

    // 2. Calculo
    int ret = abadias_pirineicas(n, v);

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