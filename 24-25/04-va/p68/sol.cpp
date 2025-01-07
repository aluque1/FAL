// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <limits.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool es_valida(int const k, vector<bool> escogidas, int const tiempo,
               int const tiempo_act) {
  if (escogidas[k]) return false;
  if (tiempo_act > tiempo) return false;
  return true;
}

bool es_solucion(int tiempo_ida, int tiempo_vuelta, int tiempo_ida_act,
                 int tiempo_vuelta_act, int punt_total, int punt_act_ida,
                 int punt_act_vuelta) {
  return (tiempo_ida >= tiempo_ida_act && tiempo_vuelta >= tiempo_vuelta_act &&
          punt_act_ida + punt_act_vuelta > punt_total && punt_act_ida > 0 &&
          punt_act_vuelta > 0);
}

// función que resuelve el problema
void resolver(int k, vector<pair<int, int>> const &canciones,
              int const time_ida, int &time_ida_act, int const time_vuelta,
              int &time_vuelta_act, int &punt_total, int &punt_act_ida,
              int &punt_act_vuelta, vector<bool> &escogida, bool &existe_sol) {
  // Cogemos la cancion para la ida
  if (es_valida(k, escogida, time_ida, time_ida_act)) {
    escogida[k] = true;
    punt_act_ida += canciones[k].second;
    time_ida_act += canciones[k].first;
    if (k == canciones.size() - 1) {
      if (es_solucion(time_ida, time_vuelta, time_ida_act, time_vuelta_act,
                      punt_total, punt_act_ida, punt_act_vuelta)) {
        punt_total = punt_act_ida + punt_act_vuelta;
        existe_sol = true;
      }
    } else {
      resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
               time_vuelta_act, punt_total, punt_act_ida, punt_act_vuelta,
               escogida, existe_sol);
    }
    escogida[k] = false;
    punt_act_ida -= canciones[k].second;
    time_ida_act -= canciones[k].first;
  }

  // Cogemos la cancion para la vuelta
  if (es_valida(k, escogida, time_vuelta, time_vuelta_act)) {
    escogida[k] = true;
    punt_act_vuelta += canciones[k].second;
    time_vuelta_act += canciones[k].first;
    if (k == canciones.size() - 1) {
      if (es_solucion(time_ida, time_vuelta, time_ida_act, time_vuelta_act,
                      punt_total, punt_act_ida, punt_act_vuelta)) {
        punt_total = punt_act_ida + punt_act_vuelta;
        existe_sol = true;
      }
    } else {
      resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
               time_vuelta_act, punt_total, punt_act_ida, punt_act_vuelta,
               escogida, existe_sol);
    }

    escogida[k] = false;
    punt_act_vuelta -= canciones[k].second;
    time_vuelta_act -= canciones[k].first;
  }

  // No cogemos ninguna cancion
  if (k == canciones.size() - 1) {
    if (es_solucion(time_ida, time_vuelta, time_ida_act, time_vuelta_act,
                    punt_total, punt_act_ida, punt_act_vuelta)) {
      punt_total = punt_act_ida + punt_act_vuelta;
      existe_sol = true;
    }
  } else {
    resolver(k + 1, canciones, time_ida, time_ida_act, time_vuelta,
             time_vuelta_act, punt_total, punt_act_ida, punt_act_vuelta,
             escogida, existe_sol);
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
  int punt_total = INT_MIN;
  int punt_act_ida = 0;
  int punt_act_vuelta = 0;

  resolver(0, canciones, time_ida, time_ida_act, time_vuelta, time_vuelta_act,
           punt_total, punt_act_ida, punt_act_vuelta, escogidas, existe_sol);

  existe_sol ? cout << punt_total : cout << "Imposible";
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
