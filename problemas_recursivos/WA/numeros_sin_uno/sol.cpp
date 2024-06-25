#include <iostream>

using namespace std;

// Problema Numero sin uno
// Resuelto en la funcion sinUno(int n)

/*
    Pre : { 0 <= n <= 1000000000 }
    Complejidad:
      Caso base tiene conste constante ya que solo es una funcion de retorno
      La llamada recursiva tiene una sola llamada recursiva en el que dividimos el numero por 2
      y tiene a su vez una operacion constante. Por estos motivos tenemos una coste O(log(n)) donde
      n es el numero pasado por parametro
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
int sinUno(int n)
{
  if(n < 10) 
    return n + 1;
  else if(n % 10 == 1)
    return sinUno(n / 10) * 9;
  else
    return sinUno(n / 10) * 9 - (9 - n % 10);
}

bool resuelveCaso()
{
  int numero;
  cin >> numero;
  if(!cin) return false;
  cout << sinUno(numero) << endl;
  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelveCaso()){}
  return 0;
}
