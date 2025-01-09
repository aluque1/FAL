// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

enum Colores { azul, rojo, verde };

/*
  Es una solucion si hemos llegado a la altura de la torre y si el asdfnumero de
  piezas rojas > num azules + num_verdes
*/
bool es_solucion(int k, vector<int> const &piezas_usadas,
                 vector<int> const &sol) {
  return (k == sol.size() &&
          piezas_usadas[rojo] > piezas_usadas[azul] + piezas_usadas[verde]);
}

/*
  Una solucion es viable si:
  1. No estamos usando mas piezas que la altura que queremos
  2: No se han usado mas piezas verdes que azules
  3: No se han usado mas piezas de las disponibles para cada color
  3: La primera pieza tiene que ser roja
  5: No se han colocado 2 verdes seguidos
*/
bool es_viable(vector<int> const &sol, int const k,
               vector<int> const &piezas_usadas,
               vector<int> const &piezas_disp) {
  if (k >= sol.size()) return false;
  if (piezas_usadas[verde] > piezas_usadas[azul]) return false;
  if (piezas_usadas[sol[k]] > piezas_disp[sol[k]]) return false;
  if (k == 0 && sol[k] != rojo) return false;
  if (k > 0 && sol[k - 1] == verde) return (sol[k] != verde);
  return true;
}

void tratar_solucion(vector<string> const &colores, vector<int> const &sol) {
  for (int i = 0; i < sol.size(); ++i) cout << colores[sol[i]] << ' ';
  cout << '\n';
}

// función que resuelve el problema
void resolver(vector<int> &sol, vector<string> const &colores, int k,
              vector<int> piezas_usadas, vector<int> piezas_disp,
              bool &existe_sol) {
  if (es_solucion(k, piezas_usadas, sol)) {
    existe_sol = true;
    tratar_solucion(colores, sol);
  }

  for (int i = 0; i < colores.size(); ++i) {
    if (k < sol.size()) {
      sol[k] = i;
      ++piezas_usadas[i];  // marcamos que pieza se acaba de usar
    }

    if (es_viable(sol, k, piezas_usadas, piezas_disp))
      resolver(sol, colores, k + 1, piezas_usadas, piezas_disp, existe_sol);

    if (k < sol.size()) {
      --piezas_usadas[i];  // desmarcamos la pieza
      sol[k] = -1;         // invalidamos lo que acabamos de hacer
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  const vector<string> colores = {"azul", "rojo", "verde"};
  int altura;
  vector<int> piezas_disp(3);

  cin >> altura >> piezas_disp[azul] >> piezas_disp[rojo] >> piezas_disp[verde];
  if (altura == 0 && piezas_disp[azul] == 0 && piezas_disp[rojo] == 0 &&
      piezas_disp[verde] == 0)
    return false;

  vector<int> sol(altura, -1);
  vector<int> piezas_usadas(colores.size(), 0);
  bool existe_sol = false;

  resolver(sol, colores, 0, piezas_usadas, piezas_disp, existe_sol);
  if (!existe_sol) cout << "SIN SOLUCION\n";
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
