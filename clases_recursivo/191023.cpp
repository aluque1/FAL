
/**
 * Para calcular la complejidad de los algoritmos recursivos es importante ver como se reduce el problema
 * en cada llamada recursiva. En el caso del factorial, en cada llamada recursiva se reduce el problema
 * en 1, por lo que la complejidad es lineal.
 *
 * Si al reduccion se hace por division entera, la complejidad es logaritmica.
 */

int fib(int n)
{
    // caso base
    if (n <= 1)
        return 1;

    // caso recursivo
    return fib(n - 1) + fib(n - 2);
}

/**
 * Tiene complejidad lineas, ya que en cada llamada recursiva se reduce restando 1.
 *
 * T(n) = a · T(n - b) + (t1 * n^k) :   b = factor de reduccion del problema , a = numero de llamadas recursivas,
 *                           ^          t1 = tiempo de ejecucion de las operaciones de la funcion, k TODO see what the n^k is
 *                           |
 *                           +----------> tiempo de ejecuccion de lo que no es la llamada recursiva
 * 
 * basicamente : a = 1 => O(n^(k+1))
 * 
 * si            a > 1 => O(a^(n/b)))
 *
 */
int fact(int n)
{
    // caso base
    if (n == 0)
        return 1;

    // caso recursivo
    return n * fact(n - 1);
}