// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema

/* PRE : { valores >= 2 ^ 0 <= n < v.size()} */
vector<int> resolver(vector<int> const &v, int const valores) {
  vector<int> sol;
  int posIni = 0;
  int cont = 1;
  /* INVARIANTE : { 0 <= posIni < v.size() ^ 1 <= cont <= valores ^ 
                    (P.t. k : posIni <= k < i : abs(v[k] - v[k + 1]) <= 1) } */
  for (int i = 1; i < v.size(); ++i) {
    if (abs(v[i] - v[i - 1]) <= 1) {  // diferencia es menor => casi llano
      ++cont;
    } else {
      posIni = i;
      cont = 1;
    }
    if (cont == valores) sol.push_back(posIni);
  }

  return sol;
}
/* POST : {i : 0 <= i < v.size() - valores + 1 ^ P.t. j : i <= j <= i + valores - 1 : abs(v[j]- v[j + 1] <= 1) } */
/* COSTE : El coste de este algoritmo es O(n) donde n es el tamaño del vector ya que se recorre el mismo
   incrementando en uno casa vez la posicion del iterador */

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int nElems, valores;
  cin >> nElems >> valores;
  if (nElems == 0 && valores == 0) return false;

  vector<int> v(nElems);
  for (int &elem : v) cin >> elem;

  vector<int> sol = resolver(v, valores);

  // escribir sol
  cout << sol.size() << ' ';
  for (int elem : sol) cout << elem << ' ';
  cout << '\n';

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