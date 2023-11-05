#include <iostream>

using namespace std;

// Problema 140 - Suma de dijitos
// Resuelto en la funcion suma(int n)

int suma(int n)
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
