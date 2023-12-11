#include <iostream>
using namespace std;

// Problema 220 - Pasa la calculadora
// Resuelto en la funcion calcula_ganador(string prefix, int n)

bool noPierde(int sumado, int n)
{
    return (sumado + n <= 31);
}

void calcula_ganador(
    /* Descripcion problema */
    int sumado,
    int n,
    /* Datos solucion parcial */
    int solParcial,
    int k
    )
{
    int sumMax = 31;


}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int sumado;
        int numero;
        // Rellenamos descripcion problema
        cin >> sumado;
        cin >> numero;

        calcula_ganador(sumado, numero, 0, 0);
    }

    return 0;
}