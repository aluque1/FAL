// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int ini, int fin) {
  if (ini >= fin) // cb : vector unico
    return v[ini]; 
  else if (ini + 1 == fin){ // cb : vector con 2 elems
    if(v[ini] < v[fin]) return v[ini];
    else return v[fin];
  }
  else { // caso recursivo
    int mid = (ini + fin) / 2;
    if(v[mid] < v[mid - 1] && v[mid] < v[mid + 1]) // mid es el minimo
      return v[mid];
    else if(v[mid] > v[mid - 1]) // estamos en zona creciente -> tenemos que buscar a la iz de mid
      return resolver(v, ini, mid);
    else // estamos en zona decreciente -> tenemos que buscar a la derecha
      return resolver(v, mid + 1, fin);
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
  for(int &elem : v)
    cin >> elem;

  int sol = resolver(v, 0, v.size() - 1);
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