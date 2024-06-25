#include <iostream>

using namespace std;

// Problema Fibonacci lineal
// Resuelto en la funcion fibonacciAcumuladores(int n)


using lli = long long int;

struct sol{
  lli n1;
  lli n2;
};

/*
    Pre : { 0 <= n <= 89 }
    Complejidad: 
      Tanto el primer como el segundo caso tienen coste cte ya que son un return.
      Al usar recursion multiple el problema se planta en territorio exponencial por lo que no es viable
      para numeros altos de n ya que O(2^n)
    Post : { return ret : fibonacci(n)}
*/
lli fiboncciMal(int n)
{
  if(n == 0) return 0;
  else if (n == 1) return 1;
  else return fiboncciMal(n-1) + fiboncciMal(n-2);
}

/* 
    Complejidad: 
      El caso base tiene O(1) ya que solo es un return. En el caso recursivo estamos disminuyendo el problema por 
      substraccion y el resto de operacion son ctes por lo tanto O(n) con respecto a n    
*/
lli fibonacciAcumuladores(int n, lli n1, lli n2){
  if(n == 0) return n2;
  else return fibonacciAcumuladores(n - 1, n1 + n2, n1);
}

/* 
    Complejidad: 
      El caso base tiene O(1) ya que son asignaciones y un return. En el caso recursivo estamos disminuyendo el problema por 
      substraccion y el resto de operacion son ctes por lo tanto O(n) con respecto a n    
*/
sol fibNoFinal(int n){
  sol s;
  if(n == 0 || n == 1){
    s.n1 = 1;
    s.n2 = 0;
    return s;
  } else {
    s = fibNoFinal(n - 1);
    lli aux = s.n1;
    s.n1 += s.n2;
    s.n2 = aux;
    return s;
  }
}


bool resuelveCaso()
{
  int numero;
  cin >> numero;
  if(numero == -1) return false;
  cout << fibNoFinal(numero).n1 << endl;
  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelveCaso()){}
  return 0;
}
