#include <iostream>

using namespace std;

// Problema Transformar un numero decimal a binario
// Resuelto en la funcion convertir(int n)

/*
    Pre : { 0 <= n <= 1000000000 }
    Complejidad:
      Caso base tiene conste constante ya que solo es una funcion de retorno
      La llamada recursiva tiene una sola llamada recursiva en el que dividimos el numero por 2
      y tiene a su vez una operacion constante. Por estos motivos tenemos una coste O(log(n)) donde
      n es el numero pasado por parametro
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
string convertir(int n)
{
  // caso base 1 : n == 0 -> return 0;
  // caso base 2 : n == 1 -> return 1;
  // caso recursivo : convertir(n/2) + char('0'+n%2)
  if (n == 0) return "0";
  else if (n == 1) return "1";
  else return convertir(n/2) + char('0' + n % 2);
}

void resuelveCaso()
{
  int numero;
  cin >> numero;
  cout << convertir(numero) << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for (int i = 0; i < num_casos; ++i)
    resuelveCaso();

  return 0;
}
