// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
int lower(vector<int> const &v, int ini, int fin) {
  if (ini >= fin)
    return ini; // cb : vector vacio
  else if (ini + 1 == fin)
    return ini; // cb : vector unico elem
  else { // caso recursivo
    int mid = (ini + fin - 1) / 2;
     /* Si el elemento que esta en la mitad es menor o igual que el siguiente a el, tenemos 
     que seguir buscandolo en la mitad izquierda*/
    if(v[mid] <= v[mid + 1])
      return lower(v, ini, mid + 1);
    else
      return lower(v, mid + 1, fin);
  }
}

int upper(vector<int> const &v, int ini, int fin) {
  if (ini >= fin)
    return ini; // cb : vector vacio
  else if (ini + 1 == fin)
    return ini; // cb : vector unico elem
  else { // caso recursivo
    int mid = (ini + fin) / 2;
     /* Si el elemento que esta a la iz de la mitad es mayor o igual que el elem a la mitad, 
     tenemos que seguir buscandolo en la mitad derecha*/
    if(v[mid - 1] >= v[mid])
      return upper(v, mid, fin);
    else
      return upper(v, ini, mid);
  }
}

int resolver(vector<int> const &v, int ini, int fin) {
  int low = lower(v, 0, v.size());
  int upp = upper(v, 0, v.size());
  return upp - low + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int nElems;
  cin >> nElems;
  if (nElems == -1)
    return false;
  vector<int> v(nElems);

  for (int &elem : v)
    cin >> elem;

  int sol = resolver(v, 0, v.size());

  // escribir sol
  nElems == 0 ? cout << "0\n" : cout << sol << '\n';
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
