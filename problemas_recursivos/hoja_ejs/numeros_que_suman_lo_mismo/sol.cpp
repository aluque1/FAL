#include <iostream>

using namespace std;

// Problema Numeros que suman lo mismo
// Resuelto en la funcion sumaDigitos(int n)

int v[10000];

/* 
    Pre : { 0 <= n <= longitud(v) <= 10000 } 
    Complejidad:
      Se puede observar que el caso base es una instruccion de return -> coste constante
      El caso recursivo es el mismo que para la implementacion no Final -> se estima el mismo
      coste de O(log(n)) siendo n el valor del entrada
    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
int sumaDigitosFinal(int n, int suma)
{
  if (n == 0)
    return suma;
  else 
    return sumaDigitosFinal(n / 10, suma + n % 10);
}

/* 
    Pre : { 0 <= n <= longitud(v) <= 10000 } 
    Complejidad:
      El caso baste tiene coste constante ya que es una instruccion de return,
      En el caso recursivo se tiene una sola llamada recursiva en el que se divide el tamaño del problema 
      mediante division (de 10) y una operacion de coste constante:
      
      T(n) = 
              c1: n < 10
              T(n/10) + c2 : n >= 10

      por lo tanto esta en el orden O(log (n)) siendo n el valor de entrada

    Post : { return ret : sum i : 0 <= i < n : v[i] }
*/
int sumaDigitosNoFinal(int n){
  if(n < 10) // Caso base
    return n;
  else // Caso recursivo
    return sumaDigitosNoFinal(n / 10) + (n % 10);
}

void resuelveCaso(){
  int num_elems; 
  int numero;
  int sum_numero;
  cin >> num_elems >> numero;
  sum_numero = sumaDigitosFinal(numero, 0);

  for(int i = 0; i < num_elems; ++i){
    cin >> v[i];
    if(sumaDigitosFinal(v[i], 0) == sum_numero)
      cout << v[i] << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
      resuelveCaso();
    }

    return 0;
}
