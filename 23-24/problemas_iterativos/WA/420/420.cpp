#include <iostream>

using namespace std;

// Ejercicio 420 El secreto de la bolsa
// Resuelto en la funcion resuelve()

void resuelve()
{
  int clave, sum = 0, cont_appear = 0;

  cin >> clave;

  string cadena;
  cin >> cadena;

  int size = cadena.length();
  int i = 0, j = 0;
  
  while(i < size && j < size)
  {
    if(sum < clave)
    {
      sum += cadena[i] - '0';
      ++i;
    }
    else if(sum > clave)
    {
      sum -= cadena[j] - '0';
      ++j;
    }
    else
    {
      cont_appear++;
      sum -= cadena[j] - '0';
      ++j;
    }
  }



  cout << cont_appear << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for (int i = 0; i < num_casos; ++i)
  {
    resuelve();
  }

  return 0;
}