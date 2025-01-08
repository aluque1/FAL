// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75
#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> &sol, int k, vector<vector<int>> const &coste, vector<bool> &visitada,
              int coste_act, int &coste_min, int const num_ciudades, int const mas_barato) {
  for (int i = 1; i < num_ciudades; ++i) {
    sol[k] = i;
    coste_act += coste[sol[k - 1]][i];
    if (!visitada[i] && coste_act < coste_min) {
      if (k == num_ciudades - 1) {
        if(coste_act + coste[sol[k]][0] < coste_min){
          coste_min = coste_act + coste[sol[k]][0];
        }
      } else {
        visitada[i] = true;
        if(coste_act + (num_ciudades - k) * mas_barato < coste_min)
          resolver(sol, k + 1, coste, visitada, coste_act, coste_min, num_ciudades, mas_barato);
        visitada[i] = false;
      }
    }
    coste_act -= coste[sol[k - 1]][i];
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_ciudades;
  cin >> num_ciudades;
  if (num_ciudades == 0) return false;

  vector<vector<int>> coste(num_ciudades, vector<int>(num_ciudades));

  for (int i = 0; i < num_ciudades; ++i) {
    for (int j = 0; j < num_ciudades; ++j) {
      cin >> coste[i][j];
    }
  }

  vector<bool> visitada(num_ciudades, false);
  int coste_min = 0;
  int mas_barato = INT_MAX;
  vector<int> sol(num_ciudades, 0);
  // Siempre salimos desde la primera ciudad
  sol[0] = 0;
  visitada[0] = true;

  // Inicializamos solucion mejor a una solucion posible
  for(int i = 1; i < num_ciudades; ++i){
    coste_min += coste[i - 1][i];
    sol[i] = i;
  }
  coste_min += coste[num_ciudades - 1][0];

  // Calculamos el minimo coste posible para estimar
  for(int i = 0; i < num_ciudades; ++i){
    for(int j = i + 1; j < num_ciudades; ++j){
      if(coste[i][j] < mas_barato) mas_barato = coste[i][j];
    }
  }  

  resolver(sol, 1, coste, visitada, 0, coste_min, num_ciudades, mas_barato);

  cout << coste_min << '\n';

  return true;
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf());  // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso());

  // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE  // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
