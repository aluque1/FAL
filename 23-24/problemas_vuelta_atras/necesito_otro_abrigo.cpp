#include <iostream>

using namespace std;

bool esValida(int solParcial[], int k, int i, int vecesPuesto[], int abrigos[], int precipitaciones[])
{
    bool valida = true;
    if ((k > 0 && solParcial[k] == solParcial[k - 1]) 
        || vecesPuesto[i] > (2 + (k / 3)) 
        || (abrigos[i] < precipitaciones[k]))
        valida = false;
    return valida;
}

void combinaAbrigos(
    /* Descripcion del problema */
    int n,
    int a,
    int precipitaciones[],
    int abrigos[],
    /* Datos solucion parcial */
    int solParcial[],
    int k,
    /* Otros parametros */
    int vecesPuesto[],
    int &ret)
{
    for (int i = 0; i < a; ++i)
    {
        solParcial[k] = i;
        vecesPuesto[i]++;
        if (esValida(solParcial, k, i, vecesPuesto, abrigos, precipitaciones))
        {
            if (k == n - 1)
            {
                if (solParcial[0] != solParcial[k])
                    ++ret;
            }
            else
                combinaAbrigos(n, a, precipitaciones, abrigos, solParcial, k + 1, vecesPuesto, ret);
        }
        vecesPuesto[i]--;
    }
}

int main()
{
    int n, a;
    while ((cin >> n >> a) && n && a)
    {
        int precipitaciones[n];
        int abrigos[a];
        for (int i = 0; i < n; i++)
            cin >> precipitaciones[i];

        for (int i = 0; i < a; i++)
            cin >> abrigos[i];
        int dummy[100];
        int veces[a];
        int ret = 0;

        combinaAbrigos(n, a, precipitaciones, abrigos, dummy, 0, veces, ret);

        if (ret == 0)
            cout << "Lo puedes comprar\n";
        else
            cout << ret << "\n";
    }
    return 0;
}