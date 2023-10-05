#include <iostream>

using namespace std;

// Ejercicio 314 Temperaturas extremas
// Resuelto en la funcion temperaturas_extremas(int v[], int n)

int v[10000];

// { Pre : 0 <= n <= longitud(v) }
void temperaturas_extremas(int v[], int n) /* return ret */
{
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
// { Post : ret = # i, j : 0 < i , j < n - 1 :
//          v[i - 1] < v[i] > v[i + 1] ^
//          v[j - 1] > v[j] < v[j + 1]}

void resuelve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    temperaturas_extremas(v, n);
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
