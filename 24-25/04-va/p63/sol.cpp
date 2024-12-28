// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool es_viable(int const k, int const i, vector<bool> const &visitada,
               int const coste_act, int const coste_min) {
  /*
    Una solucion es viable si se cumple que:
    1. El coste actual no ha sobrepasado el coste minimo.
    2. La ciudad que estamos mirando no la hemos visitado ya
  */
  if (coste_min < coste_act) return false;
  if (visitada[i]) return false;
  if (k == i) return false;
  return true;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int k, vector<vector<int>> const &coste, vector<bool> &visitada,
              int coste_act, int &coste_min) {
  for (int i = 1; i < coste.size(); ++i) {
    sol[k] = i;
    coste_act += coste[i][k];
    visitada[k] = true;
    if (es_viable(k, i, visitada, coste_act, coste_min)) {
      if (k == coste.size() - 1) {
        coste_min = min(coste_act + coste[k][0], coste_min);
      } else if (coste_act < coste_min)
        resolver(sol, k + 1, coste, visitada, coste_act, coste_min);
    }
    visitada[k] = false;
    coste_act -= coste[i][k];
    sol[k] = 0;
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
  int coste_min = INT_MAX;
  vector<int> sol(num_ciudades, 0);
  resolver(sol, 0, coste, visitada, 0, coste_min);

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
