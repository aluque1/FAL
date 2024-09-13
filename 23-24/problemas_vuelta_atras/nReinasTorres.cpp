#include <iostream>

using namespace std;

// el problema de las n-reinas y las n-torres
/*
    consiste en poner un tablero (n + t) x (n + t), poner n reinas y poner t torres en el tablero de tal forma que ninguna pieza
    se ataque entre ellas

 */

// IMPLEMENTACION DE N-REINAS Y N-TORRES
bool noAtaca(int solucion[], int ultimaColocada, bool torre)
{
    for (int i = 0; i < ultimaColocada; i++)
    {
        if (solucion[ultimaColocada] == solucion[i]) // comprueba si esta en la misma fila
            return false;
        if (!torre)
        {
            if (abs(solucion[ultimaColocada] - solucion[i]) == abs(ultimaColocada - i)) // comprueba si esta en la misma diagonal
                return false;
            if (abs(solucion[ultimaColocada] + solucion[i]) == abs(ultimaColocada + i)) // comprueba si esta en la misma diagonal
                return false;
        }
    }
    return true;
}

int nReinasYnTorresCuentaConfuguraciones(
    /* Desc problema */
    int n, // numero de reinas
    int t, // numero de torres
    /* Datos Solucion Parcial */
    int solParcial[],
    bool torre, // True si es tore, false si es reina
    int k)
{
    // CASO BASE
    if (n + t == k)
    {
        return 1;
    }

    // CASO RECURSIVO
    int ret = 0;
    for (int y = 0; y < t + n; ++y)
    {
        solParcial[k] = y;
        // si es torre
        if (torre)
        {
            if (noAtaca(solParcial, k, true))
                ret += nReinasYnTorresCuentaConfuguraciones(n, t, solParcial, true, k + 1);
        }
        // si es reina
        else
        {
            if (noAtaca(solParcial, k, false))
                ret += nReinasYnTorresCuentaConfuguraciones(n, t, solParcial, false, k + 1);
        }
    }

    return ret;
}

int main()
{
    int dummy[9 * 9];
    int n, t;
    while ((cin >> t >> n) && !(n == 0 && t == 0))
    {
        cout << nReinasYnTorresCuentaConfuguraciones(n, t, dummy, 0, true) << "\n";
    }

    return 0;
}