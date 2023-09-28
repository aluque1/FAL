#include <iostream>

using namespace std;

// Ejercicio 221 Entrando al cine
// Resuelto en la funcion resuelve()

int v[10000];

// { Pre : 0 <= n <= longitud(v) }
bool resuelve() /* return ret */
{
    int num_personas;
    int i = 0;
    cin >> num_personas;
    bool tramo_derecho;

    while (i < num_personas)
    {
        cin >> v[i];
    }
    
}
// { Post : ret = bool, i ; 0 <= i <= n : }

int main(int argc, char const *argv[])
{
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; ++i)
    {
        resuelve();
    }
    
    return 0;
}
