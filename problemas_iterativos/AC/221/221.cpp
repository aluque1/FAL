#include <iostream>

using namespace std;

// Ejercicio 221 Entrando al cine
// Resuelto en la funcion resuelve()

int v[10000];

/*  
    { Pre: 0 <= n <= longitud(v) < 10001 }
    { Post: ret = ( Ex. k : (0 <= k < n) : todosPares(v, 0, k) ^ todosImpares(v, k, n)
        donde :
        todosPares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 0 
        todosImpares(v, a, b) = P.t i : a <= i < b : v[i] mod 2 = 1 ) ^ k
    } 
    { Coste: O(n) siendo n el numero de elementos de la lista }
*/
void resuelve() 
{
  int num_personas;

  cin >> num_personas;

  for (int i = 0; i < num_personas; i++)
  {
    cin >> v[i];
  }

  bool podemos_dividir = true;
  bool tramo_par = true;
  int i = 0;
  int num_pares = 0;
  while (podemos_dividir && i < num_personas)
  {
    if (tramo_par && v[i] % 2 != 0)
      tramo_par = false;
    else if (!tramo_par && v[i] % 2 == 0)
      podemos_dividir = false;
    else if (tramo_par)
      ++num_pares;
    
    ++i;
  }

  if (podemos_dividir)
    cout << "SI " << num_pares << '\n';
  else
    cout << "NO" << endl;
  
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
