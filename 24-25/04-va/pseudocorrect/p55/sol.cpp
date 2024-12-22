// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void tratarSolucion(vector<char> const &v) {
  for (char c : v) cout << c;
  cout << '\n';
}

// función que resuelve el problema
void resolver(int m, int n, vector<char> &sol, int k, vector<bool> &marcas) {
  for (char i = 'a'; i < 'a' + m; ++i) {
    sol[k] = i;
    // exploramos la sol si podemos coger el elemento que queremos
    if (!marcas[i - 'a']) {
      marcas[i - 'a'] = true;  // hemos cogido la letra i - 'a'
      if (k == n - 1)          // Es solucion
        tratarSolucion(sol);
      else  // Seguimos explorando
        resolver(m, n, sol, k + 1, marcas);
      marcas[i - 'a'] = false;  // desmarcamos la letra para la siguiente vuelta
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int m, n;  // De las primeras m letras del abecedario vamos a elegir n
  cin >> m >> n;
  if (!std::cin) return false;
  vector<char> sol(n);     // El vector de solucion va a ser de tam n
  vector<bool> marcas(m);  // El vector de las marcas va a ser de tam m

  resolver(m, n, sol, 0, marcas);
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