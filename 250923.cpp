
/*
    Ideas principales :

    1. Resolver todo en un solo bucle, no les gusta varios bucles en una resolucion iterativa
    2. Dibujar el array, para visualizar mejor como se podria solucionar

*/

// Erasmus pretty much
long long sumaProdParejas(int v[], int n)
{
    long long ret = 0;
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

// problema 221

bool bienFormado(int v[], int n)
{
    bool primerTramo = true;
    int i = 0;

    while ((i < n) &&
           ((i == 0) ||
            (v[i] % 2 == 1) ||
            (v[i] % 2 == 0)))
    {
        ++i;
    }
}

// problema 152

// { Pre : 0 <= n <= longitud(v) ^
//          ordenado(v, n)  }
int moda(int v[], int n)
{
    // idea, llevar un contador y una variable modaAct
}
