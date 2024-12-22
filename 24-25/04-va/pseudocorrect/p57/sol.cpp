// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<string> &sol, vector<string> const &colores, int k) {
  for (int i = 0; i < colores.size(); ++i) {
    if (colores[i] != "verde" || sol[k - 1] != "verde") {
      sol[k] = colores[i];
      if (k == sol.size() - 1) {
        for (string s : sol) cout << s << ' ';
        cout << '\n';
      } else
        resolver(sol, colores, k + 1);
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int altura;
  cin >> altura;
  if (altura == 0) return false;

  vector<string> sol(altura);
  vector<string> colores = {"azul", "rojo", "verde"};
  sol[0] = colores[1];
  if(altura == 1)
    cout << "rojo\n";
  else
    resolver(sol, colores, 1);
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
