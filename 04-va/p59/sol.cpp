// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/*
  Una solucion es valida si cumple:
  1. No sobrepasemos el consumo_max
  2. No tengamos 3 colores iguales seguidos
  3. Un color no es > que la suma de todos los demas colores
*/
bool es_viable(vector<int> const &sol, int k, int consumo_act, int consumo_max,
               vector<int> &usadas, int i, int total) {
  if (consumo_act > consumo_max) return false;
  if (k > 1 && sol[k - 1] == sol[k] && sol[k - 2] == sol[k]) return false;
  // Cogemos el numero de bombillas usadas que no son del color actual
  int restoColores = total - usadas[i];
  if (usadas[i] - restoColores > 1) return false;
  return true;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int &num_tiras, vector<int> const &consumo,
              int k, int consumo_max, int consumo_act, vector<int> &usadas,
              int &total) {
  for (int i = 0; i < consumo.size(); ++i) {
    sol[k] = i;
    consumo_act += consumo[i];  // Consumo actual de las bombillas
    ++usadas[i];                // Cuantas bombillas se han usado del color i
    ++total;                    // Cuantas bombillas se han usado en total
    if (es_viable(sol, k, consumo_act, consumo_max, usadas, i, total)) {
      if (k == sol.size() - 1)
        ++num_tiras;
      else
        resolver(sol, num_tiras, consumo, k + 1, consumo_max, consumo_act,
                 usadas, total);
    }
    --usadas[i];
    --total;
    consumo_act -= consumo[i];
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int longitud, num_colores, consumo_max;
  cin >> longitud;

  if (longitud == 0) return false;
  cin >> num_colores >> consumo_max;

  vector<int> consumo(num_colores);
  vector<int> usadas(num_colores, 0);
  for (int &elem : consumo) cin >> elem;
  vector<int> sol(longitud, -1);
  int num_tiras = 0;
  int total = 0;
  // escribir sol
  resolver(sol, num_tiras, consumo, 0, consumo_max, 0, usadas, total);
  cout << num_tiras << '\n';
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
