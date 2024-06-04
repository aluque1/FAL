#include <iostream>

using namespace std;

// Ejercicio 222 Serie de potencias
// Resuelto en la funcion long potencia(int x, long n)

/* 
    { Pre: 1 <= x <= 100 ^ 0 <= n <= 1000000 }
    { Post: ret = ( Sumatorio i : 0 <= i <= n : x^i ) mod 1000007 }
    { Coste: O(n) siendo a el exponente de la serie }
 */
long long potencia(int x, long n)
{
  long long suma_acu = 0;
  long long potencia_acu = 1;

  for (int i = 0; i <= n; i++)
  {
    suma_acu += potencia_acu;
    potencia_acu *= x;
  }

  return suma_acu;
}

bool resuelve()
{
  int x;
  long n;

  if (!(cin >> x >> n))
    return false;
  else
  {
    cout << potencia(x, n) % 1000007 << '\n';
    return true;
  }
}

int main()
{

  while (resuelve()){}

  return 0;
}