// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool es_valida(vector<int> const &sol, int k, vector<bool> const escogido) {
  if (escogido[sol[k]]) return false;
  return true;
}

bool es_optima(int const satisfaccion_max, int const satisfaccion_act) {
  return satisfaccion_act >= satisfaccion_max;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int &satisfaccion_max, int k,
              int &satisfaccion_act, vector<vector<int>> satisfaccion,
              int const num_juguetes, vector<bool> &escogido) {
  for (int i = 0; i < num_juguetes; ++i) {
    sol[k] = i;
    satisfaccion_act += satisfaccion[k % sol.size()][i];
    if (es_valida(sol, k, escogido))
      if (k == sol.size() - 1 &&
          es_optima(satisfaccion_max, satisfaccion_act)) {
        satisfaccion_max = satisfaccion_act;
      } else {
        escogido[i] = true;
        resolver(sol, satisfaccion_max, k + 1, satisfaccion_act, satisfaccion,
                 num_juguetes, escogido);
        escogido[i] = false;
      }
    satisfaccion_act -= satisfaccion[k % sol.size()][i];
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_juguetes, num_niños;
  cin >> num_juguetes >> num_niños;
  if (!std::cin) return false;

  vector<int> sol(num_niños, 0);

  vector<vector<int>> satisfaccion(num_niños, vector<int>(num_juguetes));
  for (auto &row : satisfaccion) {
    for (auto &satis : row) {
      cin >> satis;
    }
  }

  int satisfaccion_max = INT_MIN;
  int satisfaccion_act = 0;
  vector<bool> escogido(num_juguetes, false);
  resolver(sol, satisfaccion_max, 0, satisfaccion_act, satisfaccion,
           num_juguetes, escogido);
  cout << satisfaccion_max << '\n';

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