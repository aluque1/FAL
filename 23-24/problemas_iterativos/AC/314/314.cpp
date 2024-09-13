#include <iostream>

using namespace std;

// Ejercicio 314 Temperaturas extremas
// Resuelto en la funcion resuelve()

int v[10000];

/*  
    { Pre : 0 <= n <= longitud(v) < 10001}
    { Post : ret = # p, v : #p = sum i : 1 <= i < n - 1 : v[i - 1] < v[i] > v[i + 1] ^
                            #v = sum i : 1 <= i < n - 1 : v[i - 1] > v[i] < v[i + 1]
    }
    { Coste : O(n) siendo n el numero de elementos de la lista }
*/
void resuelve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int i = 1;
    int num_picos = 0;
    int num_valles = 0;

    while (i < n - 1)
    {
        if((v[i - 1] < v[i]) && (v[i] > v[i + 1]))
            ++num_picos;
        if((v[i - 1] > v[i]) && (v[i] < v[i + 1]))
            ++num_valles;
        ++i;
    }
    cout << num_picos << " " << num_valles << endl;
}


int main(int argc, char const *argv[])
{
    int casos; 
    cin >> casos;

    for(int i = 0; i < casos; ++i)
    {
        resuelve();
    }

    return 0;
}
