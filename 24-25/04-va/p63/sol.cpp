// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool es_valida(vector<int> const &sol, int k, vector<bool> const &visitada) {
  if (visitada[sol[k]]) return false;
  return true;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int k, vector<vector<int>> const &coste,
              vector<bool> &visitada, int coste_act, int coste_min) {
  for (int i = 0; i < visitada.size(); ++i) {
    sol[k] = i;
    if (es_valida(sol, k, visitada)) {
      visitada[i] = true;
      coste_act += coste[k][i];
      if (k == sol.size()) {
        if (coste_act < coste_min) cout << coste_act + coste[k][0];
      } else
        resolver(sol, k + 1, coste, visitada, coste_act, coste_min);
      coste_act -= coste[k][i];
      visitada[i] = false;
    }
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

  vector<int> sol(num_ciudades);
  int coste_min = INT_MAX;
  vector<bool> visitada(num_ciudades, false);
  resolver(sol, 0, coste, visitada, 0, coste_min);
  cout << '\n';

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
