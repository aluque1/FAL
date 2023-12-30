#include <iostream>

using namespace std;

// Ejercicio 242 Erasmus
// Resuelto en la funcion erasmus(int n, int v[])

int v[100000];

/* { Pre : 0 < n <= longitud(v) } */
long long erasmus(int n, int v[])
{
  long long ret = 0;
  int i = 0;
  long long sumaAcu = 0; /* con cuanta gente podra formar 
                      pareja el siguiente grupo de personas */

  while (i < n)
  {
    // ret = Sum j, k : 0 <= j < k < i : v[j] * v[k]
    // sumaAcu = Sum j : 0 <= j < i : v[j]
    ret += sumaAcu * v[i];
    sumaAcu += v[i];
    ++i;
  }
  return ret;
}
/* { Post : ret = Sum j, k : 0 <= j < k < n : v[j] * v[k] } */

bool resuelve_caso()
{
  int n;
  cin >> n;
  if (n == 0)
    return false;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  long long ret = 0;
  ret = erasmus(n, v);
  cout << ret << "\n";
  return true;

}

int main()
{
  while (resuelve_caso())
  {
    ;
  }

  return 0;
}