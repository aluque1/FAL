#include <iostream>

using namespace std;

// Ejercicio 242 Erasmus
// Resuelto en la funcion resuelve_caso()

int v[100000];

/* 
    { Pre : 0 < n <= longitud(v) } 
    { Post : ret = Sum j, k : 0 <= j < k < n : v[j] * v[k] } 
    { Coste : O(n) }
*/
bool resuelve_caso()
{
  int n;
  long long parejas_totales = 0;
  long long presonas_disponibles = 0;
  cin >> n;
  if (n == 0)
    return false;

  for (int i = 0; i < n; i++){
    cin >> v[i];
    parejas_totales += presonas_disponibles * v[i]; // parejas_totales = Sum j, k : 0 <= j < k < i : v[j] * v[k]
    presonas_disponibles += v[i]; // sumaAcu = Sum j : 0 <= j < i : v[j]
  }
  
  cout << parejas_totales << "\n";
  return true;
}

int main()
{
  while (resuelve_caso()){}

  return 0;
}