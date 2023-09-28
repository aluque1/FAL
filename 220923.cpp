

// { Pre : 0 <= n <= longitud(v)}

int numCeros(int n, int v[])
{ /* return ret */
    int ret = 0;
    int i = 0;
    while (i < n)
    {
        if (v[i] == 0)
            ++ret;
        ++i;
    }
    return ret;
}

// { Post : ret = # i : 0 <= i < n : v[i] = 0}

// { Pre : 0 <= n <= longitud(v)}
bool hayCeros(int n, int v[]) /* return ret */
{
    int i = 0;
    while ((i < n) && (v[i] != 0)) // <---- solo se sale del bucle si se encuentra un 0
    {
        ++i;
    }

    return (i < n); // <---- es true cuando se sale del bucle
}

// { Post : ret = Ex. i : 0 <= i < n : v[i] = 0}


// { Pre : 0 <= n <= longitud(v)}
int primerCero(int n, int v[]) /* return ret */ // <---- Si no se encuentra no se encuentra se devuelve el tamaño del vector, es decir el elemento despues del ultimo
{
    int i = 0;
    while ((i < n))
    {
        /* code */
    }
    
}
// { Post : ret = max i : 0 <= i <= n
//                      : P.t. j : 0<=j < i : v[i] != 0 }