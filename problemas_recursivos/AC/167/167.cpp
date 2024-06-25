#include <iostream>

using namespace std;

// Problema 167 - Pintando fractales
// Resuelto en la funcion fractales(int l)

/* 
    Pre : { 0 <= l <= 30 } 
    Complejidad: 
    Disminucion del tam del problema por division
    - a = 1
    - b = 2
    - k = 0

    T(n) = O(n^k * log n) = O(log n) 
    Post : { }
*/
long long fractales(int l)
{
    long long l_total = 0;
    if (l <= 1)
        l_total += (l << 2);
    else
        l_total += (l << 2) + (fractales(l >> 1) << 2);

    return l_total;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        cout << fractales(n) << endl;
    }

    return 0;
}
