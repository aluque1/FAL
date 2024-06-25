#include <iostream>

using namespace std;

// Problema Calcula el numero de formas de obtener un valor con unos ciertos numeros realizando solo sumas
// Resuelto en la funcion calcula(int n, int suma)

/*
    Pre : { 0 <= n <= 1000000000 }
    Complejidad:
*/
int calcula(int n, int suma)
{
}

void resuelveCaso()
{
  int num, suma;
  cin >> num >> suma;
  cout << calcula(num, suma) << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for (int i = 0; i < num_casos; ++i)
    resuelveCaso();

  return 0;
}
