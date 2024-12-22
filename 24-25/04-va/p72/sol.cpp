// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const &v, vector<int> const &sum_acum, int sum,
              int const M, int k) {
  bool possible = false;
  if (k - 1 == v.size()) {  // caso base hemos recorrido todo el vector
    if (sum == M)
      possible = true;
  }
  /*
    Poda, si no es posible llegar a M restando todo o sumando todo lo que queda
  */
  if ((sum + sum_acum[k] >= M) && (sum - sum_acum[k] <= M)) {
    possible = resolver(v, sum_acum, sum + v[k], M, k + 1);
    possible = resolver(v, sum_acum, sum - v[k], M, k + 1);
  }
  return possible;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int wanted_sum, num_elems;

  cin >> wanted_sum >> num_elems;

  vector<int> v(num_elems);
  vector<int> sum_acum(num_elems, 0);
  for (int &elem : v) cin >> elem;

  // rellenamos el vector de acumulados reccorriendo de derecha a izquierda
  
  sum_acum[num_elems - 1] = v[num_elems - 1];
  for (int i = num_elems - 2; i >= 0; --i) sum_acum[i] = sum_acum[i + 1] + v[i];

  // como el primer numero siempre se suma podemos empezar ya con el primer
  // numero sumado por lo tanto empezamos con k = 1
  bool sol = resolver(v, sum_acum, v[0], wanted_sum, 1);

  // escribir sol
  sol ? cout << "SI\n" : cout << "NO\n";
}

int main() {
  // Para la entrada por fichero.
  // Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(
      in.rdbuf());  // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) resuelveCaso();

  // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE  // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
