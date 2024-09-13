#include <iostream>

using namespace std;

bool esValida(int sol[], int k, int marcas[])
{
    bool valida = true;
    if (sol[k] == 2) // la que acabamos de poner es verde
    {
        if ((sol[k - 1] == 2) || (marcas[0] < marcas[2])) // la anterior es verde o si hay menos azules que verdes
            valida = false;
    }
    return valida;
}

void escribirSolucion(int sol[], int k, int marcas[], bool &existe)
{
    if (marcas[1] > (marcas[0] + marcas[2]))
    {
        for (int i = 0; i < k; ++i)
        {
            if (sol[i] == 1)
                cout << "rojo ";
            else if (sol[i] == 0)
                cout << "azul ";
            else
                cout << "verde ";
        }
        cout << "\n";
        existe = true;
    }
}

void colores( // 0 = azul, 1 = rojo, 2 = verde
    /* Descripcion del problema */
    int n,
    int disponibles[],
    /* Datos solucion parcial */
    int solParcial[],
    int k,
    /* Datos adicionales */
    int marcas[],
    bool &existe)
{
    for (int i = 0; i < 3; ++i)
    {
        if (disponibles[i] > 0)
        {
            solParcial[k] = i;
            marcas[i]++;
            disponibles[i]--;
            if (esValida(solParcial, k, marcas))
            {
                // CASO BASE
                if (k == n - 1)
                {
                    escribirSolucion(solParcial, k, marcas, existe);
                }
                else
                {
                    colores(n, disponibles, solParcial, k + 1, marcas, existe);
                }
            }
            marcas[i]--;
            disponibles[i]++;
        }
    }
}

int main()
{
    int n, a, r, v;

    while ((cin >> n >> a >> r >> v) && n && a && r && v)
    {
        int marcas[4] = {0, 0, 0, 0};
        int dummy[100];
        int disponibles[3] = {a, r - 1, v}; // hay un rojo menos porque el primero es rojo
        dummy[0] = 1;                       // el primer color es rojo
        marcas[1] = 1;                      // hay un rojo
        bool existe = false;
        if (n > 1)
            colores(n, disponibles, dummy, 1, marcas, existe);
        else
            cout << "rojo\n";

        if (!existe)
            cout << "SIN SOLUCION\n";
        cout << "\n";
    }
}