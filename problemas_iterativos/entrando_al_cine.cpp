#include <iostream>

using namespace std;

// Ejercicio 221 Entrando al cine
// Resuelto en la funcion entrando_al_cine(int v[], int n)

int v[10000];

void entrando_al_cine(int v[], int n)
{
    int i = 0;
    int num_par = 0;
    bool tramo_impar = false;
    bool tramo_par = true;

    while (i < n)
    {
        if (tramo_par && (v[i] % 2 != 0))
        {
            tramo_par = false;
            tramo_impar = true;
        }
        else
            ++num_par;
        ++i;
    }
    if (i == n) // esto es igual que decir que es correct ya que ha recorrido todo el vector
        cout << "SI " << num_par << endl;
    else
        cout << "NO" << endl;
}

// { Pre : 0 <= n <= longitud(v) }
void resuelve() /* return ret */
{
    int num_personas;

    cin >> num_personas;

    for (int i = 0; i < num_personas; i++)
    {
        cin >> v[i];
    }
    entrando_al_cine(v, num_personas);

    
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
