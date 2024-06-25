#include <iostream>

using namespace std;

// Problema Numeros que suman lo mismo
// Resuelto en la funcion invertir(int n)

/*
    Pre : { 0 <= n <= 1000000000 }
    Complejidad:
      Caso base tiene conste constante ya que solo es una funcion de retorno
      La llamada recursiva tiene una sola llamada recursiva en el que dividimos el numero por 10
      y tiene a su vez una operacion constante. Por estos motivos tenemos una coste O(log(n)) donde
      n es el numero pasado por parametro
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
struct sol
{
  int num;
  int pot;
};

sol invertir(int n)
{
  // caso base : n < 10 -> s.pot = 1, s.num = n, return s;
  // caso recursivo : s = invertir(n/10), s.pot *= 10, s.num = s.num + n % 10 * s.pot, return s;
  sol s;
  if (n < 10)
  { // caso base
    s.pot = 1;
    s.num = n;
    return s;
  }
  else
  {
    s = invertir(n / 10);
    s.pot *= 10;
    s.num = s.num + n % 10 * s.pot;
    return s;
  }
}

bool resuelveCaso()
{
  int numero;
  cin >> numero;

  if (!cin) return false;

  cout << invertir(numero).num << endl;
  return true;
}

int main(int argc, char const *argv[])
{
  while (resuelveCaso())
  {
  }

  return 0;
}
