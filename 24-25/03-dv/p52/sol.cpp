// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct t_ronda {
  int num_ronda;     // Indicador de ronda
  int num_partidos;  // Num de partidos totales
  bool jugada;       // Si la ronda se ha jugado o no
};

// función que resuelve el problema
t_ronda resolver(vector<string> const &datos, int ini, int fin) {
  if (ini + 2 == fin) {
    return {1,
            datos[ini].compare("NP") != 0 && datos[fin - 1].compare("NP") != 0,
            datos[ini].compare("NP") != 0 || datos[fin - 1].compare("NP") != 0};
  } else {
    int mid = (ini + fin) / 2;
    auto iz = resolver(datos, ini, mid);
    auto dr = resolver(datos, mid + 1, fin);

    
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_elems, num_rondas;
  cin >> num_elems;
  if (!std::cin) return false;
  cin >> num_rondas;

  vector<string> jugadores(num_elems);
  for (string &elem : jugadores) cin >> elem;

  cout << resolver(jugadores, 0, num_elems).num_partidos << '\n';
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