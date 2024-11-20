// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
  if(ini == fin - 1) // vector 1 elemento
    return v[ini];
  else if(ini == fin - 2)// vector 2 elementos
    return v[ini] < v[ini + 1] ? v[ini] : v[ini + 1];
  else {
    int mid = (ini + fin) / 2;
    int minIz = min(v[ini], v[mid - 1]); 
    int minDr = min(v[mid], v[fin - 1]);

    if(minIz < minDr) return resolver(v, ini, mid);
    else return resolver(v, mid, fin);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int nElems;
  cin >> nElems;
  if (!std::cin)
    return false;

  vector<int> v(nElems);

  for(int & elem : v)
    cin >> elem;
  
  int sol = resolver(v, 0, v.size());
  // escribir sol
  cout << sol << '\n';

  return true;
}

int main() {
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso())
    ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}