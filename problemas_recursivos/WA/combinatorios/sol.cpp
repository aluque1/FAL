#include <iostream>

using namespace std;

// Problema Numero Combinatorios
// Resuelto en la funcion Combinatorios

/*
    Pre : { 0 <= n <= 89 }
    Complejidad:
      
*/
using tMatrix = int[INT16_MAX][INT16_MAX]; 

int combinatoria(int a, int b, tMatrix matriz){
  if(b == 0 || a == b) return matriz[a][b] = 1;
  else if (b == 1 || b == a - 1) return matriz[a][b] = 1;
  else{
    if(matriz[a - 1][b - 1] == - 1) matriz[a - 1][b - 1] = combinatoria(a - 1, b - 1, matriz);
    if(matriz[a - 1][b] == - 1) matriz[a - 1][b] = combinatoria(a - 1, b, matriz);
    return matriz[a][b] = matriz[a - 1][b - 1] + matriz[a - 1][b];
  }
}

bool resuelveCaso()
{
  int a, b;
  cin >> a >> b;
  if(!cin) return false;
  tMatrix matriz;
  for(int i = 0; i < b; ++i){
    for(int j = 0; j < a; ++i){
      matriz[i][j] = -1;
    }
  }
  cout << combinatoria(a,b,matriz) << endl;;

  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelveCaso()){}
  return 0;
}
