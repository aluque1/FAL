#include <iostream>

using namespace std;

// Variacion de m elementos cogidos de n en n sin repeticion

void variaciones(
    /* Descripcion del problema */
    int m,
    int n,
    /* Solucion parcial */
    string solParcial,
    int k,
    /* Otros parametros */
    bool marcas[])
{
    for (char c = 'a'; c < 'a' + m; ++c)
    {

        if (k == n)
        {
            cout << solParcial << "\n";
            return;
        }
        else
        {
            if (!marcas[c - 'a'])
            {
                marcas[c - 'a'] = true;
                variaciones(m, n, solParcial + c, k + 1, marcas);
                marcas[c - 'a'] = false;
            }
        }
        // CASO BASE
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    string sol = "";
    while (cin >> m >> n && n != 0 && m != 0)
    {
        bool marcas[m] = {false};
        variaciones(m, n, sol, 0, marcas);
        cout << "\n";
    }

    return 0;
}