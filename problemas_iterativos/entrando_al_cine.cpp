#include <iostream>

using namespace std;

// Ejercicio 221 Entrando al cine
// Resuelto en la funcion resuelve()

int v[10000];

// { Pre : 0 <= n <= longitud(v) }
void resuelve() /* return ret */
{
    int num_personas;
    int i = 0;
    cin >> num_personas;
}
// { Post: ret = Ex. k : (0 <= k < n)
//                     : todosPares(v, 0, k) ^
//                       todosImpares(v, k, n)
// donde : 
//      todosPares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 0 <-----+ nos fijamos que a esta dentro de v[i] mienstras b no lo esta
//      todosImpares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 1 <---+   
// }

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
