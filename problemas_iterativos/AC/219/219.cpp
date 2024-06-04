#include <iostream>

using namespace std;

// Ejercicio 219 Loteria Peña Atletica
// Resuelto en la funcion resuelve()

int v[100000]; 

/* 
    { Pre: 0 <= n <= longitud(v) < 10001}
    { Post: ret = #i : 0 <= i < n ; v[i] % 2 = 0 }
    { Coste: O(n) siendo n el numero de elementos de la lista }
*/
bool resuelve()
{
    int ret = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        if(v[i] % 2 == 0)
            ++ret;
    }
    cout << ret << endl;
    return true;
}

int main(int argc, char const *argv[])
{
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i)
    {
        resuelve();
    }
    
    return 0;
}
