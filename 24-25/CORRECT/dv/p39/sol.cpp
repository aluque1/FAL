// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// funciónes que resuelve el problema

// Funcion que busca la posicion mas a la izquierda del elemento
int binSearchIz(vector<int> const &v, int s, int ini, int fin) {
  if (ini >= fin)
    return ini;
  else if (ini + 1 == fin)
    return ini;
  else {
    int mitad = (ini + fin - 1) / 2;
    if (v[mitad] < s)
      return binSearchIz(v, s, mitad + 1, fin);
    else
      return binSearchIz(v, s, ini, mitad + 1);
  }
}

// Funcion que busca la posicion mas a la derecha del elemento
int binSearchDr(vector<int> const &v, int s, int ini, int fin) {
  if (ini >= fin)
    return ini;
  else if (ini + 1 == fin)
    return ini;
  else {
    int mitad = (ini + fin) / 2;
    if (s < v[mitad])
      return binSearchDr(v, s, ini, mitad);
    else
      return binSearchDr(v, s, mitad, fin);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, altura;
  cin >> n;
  if (!std::cin)
    return false;
  cin >> altura;
  vector<int> v(n);
  for (int &elem : v)
    cin >> elem;

  int pIz = binSearchIz(v, altura, 0, (int)v.size());
  if (pIz == v.size() ||
      v[pIz] != altura) // Si llegamos al final o no hemos encontrado la altura
    cout << "NO EXISTE\n";
  else { // Si hemos encontrado la altura buscamos la ultima ocurrencia
    int pDr = binSearchDr(v, altura, 0, (int)v.size());
    pIz == pDr ? cout << pIz << '\n' : cout << pIz << ' ' << pDr << '\n';
  }
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