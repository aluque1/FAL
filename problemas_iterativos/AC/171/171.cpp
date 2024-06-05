#include <iostream>

using namespace std;

// Ejercicio 171 Abadias pirenaicas
int v[100000];

/* 
    { Pre : 0 < n <= longitud(v) <= 100000 }
    { Post : ret = Sum i : i = abadia(i, v) 
      donde abadia(i, v) = i < j < n : v[i] > v[j]}
    { Coste : O(n) ya que se recorre todo el array } 
*/
bool resuelve_caso()
{
  int n; 
  cin >> n;

  if (n == 0)
    return false;

  for (int i = 0; i < n; ++i)
    cin >> v[i];
  
  int numero_abadias = 1;
  int max_altura = v[n-1];

  for(int i = n-2; i >= 0; --i){
    if(v[i] > max_altura){
      ++numero_abadias;
      max_altura = v[i];
    }
  }

  cout << numero_abadias << "\n";
  return true;
}

int main()
{
  while (resuelve_caso()){}

  return 0;
}