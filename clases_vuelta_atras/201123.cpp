#include <iostream>

using namespace std;

// el problema de las n-reinas
/*
    consiste en poner un tablero n x n y poner n reinas en el tablero de tal forma que no se ataquen entre ellas
    para un tablero 4 x 4 habria que colocar 4 reinas de tal forma que no se ataquen entre ellas

    0 0 1 0
    1 0 0 0     el 1 representa una reina
    0 0 0 1     el 0 representa una casilla vacia
    0 1 0 0

    de ahora en adelante en vez de usar "prefijo como usamos en la solucion de helados en 171123.cpp" tendremos lo siguiente:
        · solucion              La solucion final que cumple la restriccion del enunciado
        · solucion parcial      Una solucion que no se llega a saber si cumple la restriccion del enunciado y todavia le quedan casos sin probar
        · solucion prometedora  Una solucion parcial que tiene pinta de ser solucion, en el momento que se rompe pasa a ser una solucion parcial
 */

/* esquema de solucion vuelta atras */

typedef int TSolucionPseudo;

bool esCompleta(TSolucionPseudo solParcial, int k);

/* Pre : solParcial es prometedora, si no lo es pasa a ser un algoritmo de fuerza bruta */
void vueltas(
    /* Descripcion del problema */
    int n, // ...
    /* Solucion parcial */
    TSolucionPseudo solParcial, // sol. parcial
    int k                       // cuantos elementos hay añadidos a la solucion parcial
    /* Otros parametros */
)
{
    // CASO BASE (IF solParcial == solucion THEN) NO se comprueba si solParcial == solucion
    if (esCompleta(solParcial, k))
    {
        int x = 0; // procesamos solucion
    }

    // CASO RECURSIVO
    /*
    para cada posible decision
    {
        nuevaSol = extiendeSolParcial(solParcial, decision);
        if (esPrometedora(nuevaSol))
            vueltaAtras(n, nuevaSol, k + 1)
    }
    */
}

// IMPLEMENTACION DE N-REINAS
void escribeTablero(int sol[], int n)
{
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            // prints the board
        }
    }
}

bool noAtaca(int solucion[], int ultimaColocada)
{
    // posibles mejoras aqui: marcaje, Ademas de llevar la solParcial, otros datos que nos facilita ver si la solParcial es correcta
    // En este caso un array de bool para las filas y otro para las diagonales
    for (int i = 0; i < ultimaColocada; i++) 
    {
        if (solucion[ultimaColocada] == solucion[i]) // comprueba si esta en la misma fila
            return false;
        if (abs(solucion[ultimaColocada] - solucion[i]) == abs(ultimaColocada - i)) // comprueba si esta en la misma diagonal
            return false;
    }
    return true;
}

void nReinas(
    /* Desc problema */
    int n, // numero de reinas
    /* Datos Solucion Parcial */
    int solParcial[],
    int k)
{
    if (n == k)
    {
        escribeTablero(solParcial, n),
            cout << "\n";
        return;
    }

    for (int y = 0; y < n; ++y)
    {
        solParcial[k] == y;
        if (noAtaca(solParcial, k))
            nReinas(n, solParcial, k + 1);
    }
}

int nReinasCuentaConfuguraciones(
    /* Desc problema */
    int n,
    /* Datos Solucion Parcial */
    int solParcial[],
    int k)
{
    if (n == k)
        return 1;

    int ret = 0;
    for (int y = 0; y < n; ++y)
    {
        solParcial[k] = y;
        if (noAtaca(solParcial, k))
            ret += nReinasCuentaConfuguraciones(n, solParcial, k + 1);
    }

    return ret;
}

int main()
{
    int dummy[100];
    int cuantas = nReinasCuentaConfuguraciones(4, dummy, 0);
    cout << "Con un tablero de 4x4 hay " << cuantas << "confuguraciones \n";

    return 0;
}