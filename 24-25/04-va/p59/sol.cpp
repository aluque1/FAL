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
*/
bool es_valida(vector<int> const &sol, int k, int consumo_act, int consumo_max){
  if(consumo_act > consumo_max) return false;
  if(sol[k - 1] == sol[k] && sol[k - 1] == sol[k]) return false;
  return true;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int &num_tiras, vector<int> const &consumo, int k, int consumo_max, int consumo_act) {
  if(k == sol.size()) // Es una solucion
    ++num_tiras;

  for(int i = 0; i < sol.size(); ++i){
    
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int longitud, num_colores, consumo_max;
  cin >> longitud;

  if (longitud == 0) return false;
  cin >> num_colores, consumo_max;

  vector<int> consumo(num_colores);
  for (int &elem : consumo) cin >> elem;
  vector<int> sol(longitud, -1);
  int num_tiras = 0;
  // escribir sol
  resolver(sol, num_tiras, consumo, 0, consumo_max, 0);
  cout << num_tiras  << '\n';
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
