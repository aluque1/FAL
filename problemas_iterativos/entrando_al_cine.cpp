#include <iostream>

using namespace std;

// Ejercicio 221 Entrando al cine
// Resuelto en la funcion entrando_al_cine(int v[], int n)

int v[10000];

// { Pre : 0 <= n <= longitud(v) }
void resuelve() /* return ret */
{
    int num_personas;
    int i = 0;
    string ret = "SI";
    bool correct = true;
    bool tramo_impar = false;
    bool tramo_par = true;

    cin >> num_personas;

    while ((i < num_personas) && correct)
    {
        cin >> v[i];
        if (tramo_par &&(v[i] % 2 != 0)){
            tramo_par = false;
            tramo_impar = true;
        }

        if (tramo_impar && (v[1] % 2 == 0))
        {
            correct = false;
            ret = "NO";
        }
        ++i;
    }
    cout << ret << endl;
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
