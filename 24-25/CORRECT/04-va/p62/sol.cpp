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

bool es_prometedora(int const satisfaccion_act, vector<int> const &acumulados,
                    int const satisfaccion_max, int const k) {
  return (satisfaccion_act + acumulados[k + 1] > satisfaccion_max);
}

// función que resuelve el problema
void resolver(vector<int> &sol, int &satisfaccion_max, int k,
              int &satisfaccion_act, vector<vector<int>> satisfaccion,
              int const num_juguetes, vector<bool> &escogido,
              vector<int> const &acumulados) {
  for (int i = 0; i < num_juguetes; ++i) {
    sol[k] = i;
    if (es_valida(sol, k, escogido)) {
      satisfaccion_act += satisfaccion[k][i];
      escogido[i] = true;
      if (k == sol.size() - 1){
        if(es_optima(satisfaccion_max, satisfaccion_act))
          satisfaccion_max = satisfaccion_act;
      } else {
        if (es_prometedora(satisfaccion_act, acumulados, satisfaccion_max, k)) {
          resolver(sol, satisfaccion_max, k + 1, satisfaccion_act, satisfaccion,
                   num_juguetes, escogido, acumulados);
        }
      }
      escogido[i] = false;
      satisfaccion_act -= satisfaccion[k][i];
    } 
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_juguetes, num_ninios;
  cin >> num_juguetes >> num_ninios;
  if (!std::cin) return false;

  vector<int> sol(num_ninios, 0);

  /*
    Para inicializar el vector de acumulados queremos ir cogiendo lo mejor que
    tenemos de todas las satisfacciones esto es porque para la estimacion vamos
    a hacer los siguiente:
      Vamos a guardar la mayor satisfaccion para cada niño y vamos a ver si la
      satisfaccion actual + la suma total de maximo que se puede conseguir.
  */
  vector<int> acumulados(num_ninios);

  vector<vector<int>> satisfaccion(num_ninios, vector<int>(num_juguetes));
  for (int i = 0; i < num_ninios; ++i) {
    int aux_max = satisfaccion[i][0];
    for (int j = 0; j < num_juguetes; ++j) {
      cin >> satisfaccion[i][j];
      if (aux_max < satisfaccion[i][j]) aux_max = satisfaccion[i][j];
    }
    acumulados[i] = aux_max;
  }

  for (int i = acumulados.size() - 1; i > 0; --i)
    acumulados[i - 1] += acumulados[i];

  int satisfaccion_max = 0;
  // Inicializamos satisfaccion_max a algo que sea "medianamente optimo"
  for (int i = 0; i < num_ninios; ++i) satisfaccion_max += satisfaccion[i][i];

  int satisfaccion_act = 0;
  vector<bool> escogido(num_juguetes, false);
  resolver(sol, satisfaccion_max, 0, satisfaccion_act, satisfaccion,
           num_juguetes, escogido, acumulados);
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