#include <iostream>

using namespace std;

// Variacion de m elementos cogidos de n en n con repeticion

void variaciones(
    /* Descripcion del problema */
    int m, // m elementos. Las letras van de 'a' hasta 'a' + m
    int n, // n elementos cogidos
    /* Solucion parcial */
    string solParcial, // Solucion parcial hasta el momento
    int k              // cuantos elementos hay añadidos a la solucion parcial
)
{
    for (char c = 'a'; c < 'a' + m; ++c)
    {
        // CASO BASE
        if (k == n)
        {
            cout << solParcial << "\n";
            return;
        }
        else // CASO RECURSIVO
        {
            variaciones(m, n, solParcial + c, k + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    string sol = "";
    while (cin >> m >> n && n != 0 && m != 0)
    {
        variaciones(m, n, sol, 0);
        cout << "\n";
    }

    return 0;
}
