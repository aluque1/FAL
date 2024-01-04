#include <iostream>

using namespace std;

// Problema 140 - Suma de dijitos
// Resuelto en la funcion suma(int n)

/* Pre : { 0 <= n , 10^9 } */
int suma(int n) /* return ret */
{
    int sum = 0;

    if (n < 10) // caso base
    {
        sum += n;
    }
    else // caso recursivo
    {
        sum += n % 10 + suma(n / 10);
        cout << " + ";
    }

    cout << n % 10;
    return sum;
}

/*  
    Complejidad
    Disminucion del tam del problema por division =>
    - a = 1
    - b = 10
    - k = 0

    T(n) = O(n^k * log n) = O(log n)
*/

/* Post : { ret = sum i : 0 <= i < n : n%10 } */

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n > -1)
    {
        int sum = suma(n);
        cout << " = " << sum << endl;
        cin >> n;
    }

    return 0;
}
