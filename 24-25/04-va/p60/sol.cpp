// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void tratar_solucion(vector<int> const &sol) {
  for(int regalo : sol) cout << regalo << ' ';
  cout << '\n';
}

bool es_valida(vector<int> const &sol, int k,
               vector<string> const &tipo_jugete) {
  /*
    Si estamos en una posicion impar del vector y
    Si el jugete de antes es mayor o igual que el siguiente, tenemos jugetes
    repetidos => se ha asignado mal
  */
  if(k % 2 != 0 && tipo_jugete[sol[k - 1]] == tipo_jugete[sol[k]]) return false;
  if(k % 2 != 0 && sol[k - 1] > sol[k]) return false;
  return true;
}

// función que resuelve el problema
void resolver(vector<int> &sol, int k, bool &existe_sol,
              vector<string> const &tipo_jugete) {
  for (int i = 0; i < tipo_jugete.size(); ++i) {
    sol[k] = i;
    if (es_valida(sol, k, tipo_jugete)) {
      if (k == sol.size() - 1) {
        tratar_solucion(sol);
        existe_sol = true;
      } else {
        resolver(sol, k + 1, existe_sol, tipo_jugete);
      }
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_jugetes, num_niños;
  cin >> num_jugetes >> num_niños;

  if (!std::cin) return false;

  vector<string> tipo_jugete(num_jugetes);
  for(int i = 0; i < num_jugetes; ++i){
    cin >> tipo_jugete[i];
  }
  
  vector<int> sol(num_niños * 2);
  bool existe_sol = false;

  resolver(sol, 0, existe_sol, tipo_jugete); 
  existe_sol ? cout << '\n' : cout << "SIN SOLUCION\n\n";
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