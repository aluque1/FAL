// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(int k, vector<pair<int, int>> const &canciones,
              int const time_ida, int &time_ida_act, int const time_vuelta,
              int &time_vuelta_act, int &punt_max, int &punt_act,
              vector<bool> &escogida, bool &existe_sol, vector<int> const &acum) {
  // Cogemos la cancion para la ida
  if (!escogida[k]) {
    escogida[k] = true;
    punt_act += canciones[k].second;
    time_ida_act += canciones[k].first;
    if(time_ida_act <= time_ida){
      if (k == canciones.size() - 1) {
        if(time_ida_act == time_ida && time_vuelta_act == time_vuelta){
          punt_max = max(punt_act, punt_max);
          existe_sol = true;
        }
      } else if(punt_act + acum[k + 1] > punt_max){
        resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
               time_vuelta_act, punt_max, punt_act, escogida, existe_sol, acum);
      }
    }
    escogida[k] = false;
    punt_act -= canciones[k].second;
    time_ida_act -= canciones[k].first;
  }

  // Cogemos la cancion para la vuelta
  if (!escogida[k]) {
    escogida[k] = true;
    punt_act += canciones[k].second;
    time_vuelta_act += canciones[k].first;
    if(time_vuelta_act <= time_vuelta){
      if (k == canciones.size() - 1) {
        if(time_ida_act == time_ida && time_vuelta_act == time_vuelta){
          punt_max = max(punt_act, punt_max);
          existe_sol = true;
        }
      } else if(punt_act + acum[k + 1] > punt_max){
        resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
               time_vuelta_act, punt_max, punt_act, escogida, existe_sol, acum);
      }
    }
    escogida[k] = false;
    punt_act -= canciones[k].second;
    time_vuelta_act -= canciones[k].first;
  }

  // No cogemos ninguna cancion
  if (k == canciones.size() - 1) {
    if(time_ida_act == time_ida && time_vuelta_act == time_vuelta){
          punt_max = max(punt_act, punt_max);
          existe_sol = true;
    }
  } else if(punt_act + acum[k + 1] > punt_max){
        resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
               time_vuelta_act, punt_max, punt_act, escogida, existe_sol, acum);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num_canciones, time_ida, time_vuelta;
  cin >> num_canciones >> time_ida >> time_vuelta;
  if (num_canciones == 0 && time_ida == 0 && time_vuelta == 0) return false;

  // first = duracion, second = puntuacion
  vector<pair<int, int>> canciones(num_canciones);
  for (int i = 0; i < num_canciones; ++i)
    cin >> canciones[i].first >> canciones[i].second;

  // Para saber que canciones se han escogido ya
  vector<bool> escogidas(num_canciones, false);
  bool existe_sol = false;
  int time_ida_act = 0;
  int time_vuelta_act = 0;
  int punt_max = INT_MIN;
  int punt_act = 0;

  vector<int> acum(num_canciones, 0);
  acum[num_canciones - 1] = canciones[num_canciones - 1].second;
  for(int i = num_canciones - 2; i >= 0; --i) 
    acum[i] = acum[i + 1] + canciones[i].second;

  resolver (0, canciones, time_ida, time_ida_act, time_vuelta,
            time_vuelta_act, punt_max, punt_act, escogidas, existe_sol, acum);

  existe_sol ? cout << punt_max : cout << "Imposible";
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
