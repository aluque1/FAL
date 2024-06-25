#include <iostream>

using namespace std;

// Problema Numeros que suman lo mismo
// Resuelto en la funcion jugandoDigitos(int n)

/*
    Pre : { 0 <= n <= 1000000000 }
    Complejidad:  
      Caso base tiene conste constante ya que solo es una funcion de retorno
      La llamada recursiva tiene una sola llamada recursiva en el que dividimos el numero por 10
      y tiene a su vez una operacion constante. Por estos motivos tenemos una coste O(log(n)) donde
      n es el numero pasado por parametro
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
int jugandoDigitos(int n)
{
  int digito;
  if(n < 10){ // caso base
    if(n % 2 == 0)
      return (n % 10) + 1;
    else
      return (n % 10) - 1;
  }
  else{
    if(n % 2 == 0)
      digito = (n % 10) + 1;
    else 
      digito = (n % 10) + 1;
    return jugandoDigitos(n / 10) * 10 + digito;
  } 
    
}

void resuelveCaso()
{
  int numero;
  cin >> numero;
  cout << jugandoDigitos(numero) << endl;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    resuelveCaso();
  }

  return 0;
}
