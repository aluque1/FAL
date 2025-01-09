// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> &sol, int &satisfaccion_max, int k,
              int &satisfaccion_act, vector<vector<int>> satisfaccion,
              int const num_juguetes, vector<bool> &escogido, vector<int> const &acum) {
  for (int i = 0; i < num_juguetes; ++i) {
    sol[k] = i;
    if (!escogido[sol[k]]){
      escogido[i] = true;
      satisfaccion_act += satisfaccion[k][i];
      if (k == sol.size() - 1){
        if(satisfaccion_act > satisfaccion_max) satisfaccion_max = satisfaccion_act;
      } else {
        if(satisfaccion_act + acum[k + 1] > satisfaccion_max)
        resolver(sol, satisfaccion_max, k + 1, satisfaccion_act, satisfaccion,
                 num_juguetes, escogido, acum);
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
  int num_juguetes, num_niños;
  cin >> num_juguetes >> num_niños;
  if (!std::cin) return false;

  vector<int> sol(num_niños, 0);
  vector<vector<int>> satisfaccion(num_niños, vector<int>(num_juguetes));
  
  for(int i = 0; i < num_niños; ++i){
    for (int j = 0; j < num_juguetes; ++j) {
      cin >> satisfaccion[i][j];
    }
  }

  vector<int> acum(num_niños);
  for (int i = 0; i < num_niños ; ++ i){
    int aux_max = satisfaccion[i][0];
    for (int j = 1; j < num_juguetes ; ++ j)
      if(aux_max < satisfaccion[i][j]) aux_max = satisfaccion[i][j];
    acum[i] = aux_max;
  }

  for(int i = acum.size() - 1; i > 0; --i) acum[i - 1] += acum[i];

  int satisfaccion_max = 0;
  for(int i = 0; i < num_niños; ++i) satisfaccion_max += satisfaccion[i][i];
  int satisfaccion_act = 0;

  vector<bool> escogido(num_juguetes, false);
  resolver(sol, satisfaccion_max, 0, satisfaccion_act, satisfaccion,
           num_juguetes, escogido, acum);
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