#include <iostream>

using namespace std;

// Ejercicio 171 Abadias pirenaicas
int v[100000];

/* Pre : 0 < n <= longitud(v) */
/* Complejidad : O(n) ya que se recorre todo el array */
void resuelve_caso(int n)
{
  int cont = 1;
  int maxAltura = v[n-1];

  for(int i = n-2; i >= 0; --i){
    if(v[i] > maxAltura){
      ++cont;
      maxAltura = v[i];
    }
  }

  cout << cont << "\n";
}
/* Post : ret = i : i = max(j) : v[j] < v[j+1]*/

int main()
{
  int n;
  while ((cin >> n) && n)
  {
    for (int i = 0; i < n; ++i)
    {
      cin >> v[i];
    }
    resuelve_caso(n);
  }
}