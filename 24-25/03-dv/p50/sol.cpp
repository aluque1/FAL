// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

using matrix = vector<vector<int>>;

// función que resuelve el problema
pair<bool, int> resolver(matrix const &parcelas, int ini_col, int fin_col, int ini_row, int fin_row) {
  if(ini_row + 1 == fin_row) return {true, parcelas[ini_row][ini_col]};
  else {
    int mid_row = (ini_row + fin_row) / 2;
    int mid_col = (ini_col + fin_col) / 2;
    int n = fin_row - ini_row;
    int num_parcelas = n*n;

    auto iz_arriba = resolver(parcelas, ini_row, mid_row, ini_col, mid_col);
    auto dr_arriba = resolver(parcelas, ini_row, mid_row, mid_col, fin_col);
    auto iz_abajo = resolver(parcelas, mid_row, fin_row, ini_col, mid_col);
    auto dr_abajo = resolver(parcelas, mid_row, fin_row, mid_col, fin_col);

    int num_labranza = iz_arriba.second + dr_arriba.second + iz_abajo.second + dr_abajo.second;

    if (iz_arriba.first && dr_arriba.first && iz_abajo.first && dr_abajo.first 
        && num_labranza >= (num_parcelas - 1) / 4 
        && num_labranza <= (3 * num_parcelas) / 4
        && abs(iz_arriba.second - dr_arriba.second) <= 2 
        && abs(iz_arriba.second - iz_abajo.second) <= 2
        && abs(iz_arriba.second - dr_abajo.second) <= 2 
        && abs(dr_arriba.second - iz_abajo.second) <= 2 
        && abs(dr_arriba.second - dr_abajo.second) <= 2
        && abs(iz_abajo.second - dr_abajo.second) <= 2 ){
      return {true, num_labranza};
    } else { 
      return {false, 1};
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int num_filas;
  cin >> num_filas;
  matrix parcelas(num_filas, vector<int>(num_filas));

  for(int i = 0; i < num_filas; ++i){
    for(int j = 0; j < num_filas; ++j){
      cin >> parcelas[i][j];
    }
  }

  auto sol = resolver(parcelas, 0, parcelas.size(), 0, parcelas.size());

  // escribir sol
  sol.first ? cout << "SI\n" : cout << "NO\n";
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