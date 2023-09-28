

bool esParV1(int n){ // esta version obviamente es una mierda
    bool ret = true;

    int i = 0;

    while (i < n)
    {
        ret = !ret;
        ++i;
    }
    
    return ret;
}

bool esParV2(int n){ // mejor que la anterior pero sigue siendo lento
    while (n>1)
    {
        n-=2;

    }
    return (n == 0);
}


bool esParV3(int n){ // esta es la buena
    return (n%2 == 0);
}

bool esParV4(int n){ // esta es hasta mas rapida
    return !(n & 1);
}

/* 
Si nos vijamos en la v1, v2, y v3 no son algoritmos validos ya que no son exahustivos, no tienen en cuenta
los numeros negativos. Si el enunciado dice que tambien tiene que funcionar para numeros negativos este es el
caso, si dice que es solo para numeros positivos si son funcionales
*/

int factorial(int n){ // la complejidad del factorial es lineal porque se hace n llamadas 
    if (n == 0)
        return 1;
    
    return n * factorial(n-1);
}