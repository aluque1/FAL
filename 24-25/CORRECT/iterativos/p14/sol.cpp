// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, int> resolver(vector<int> const &v, int altura)
{
  int tramoMax = 0, tramoAct = 0, posIniMax = 0, posIniAct = 0;

  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i] > altura)
    {
      if (tramoAct == 0)
        posIniAct = i;
      ++tramoAct;
      if (tramoAct > tramoMax)
      {
        tramoMax = tramoAct;
        posIniMax = posIniAct;
      }
    }
    else
      tramoAct = 0;
  }
  return {posIniMax, posIniMax + tramoMax - 1};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer los datos de la entrada
  int numElems, altura;
  cin >> numElems >> altura;

  vector<int> v(numElems);

  for (int &elem : v)
    cin >> elem;

  pair<int, int> sol = resolver(v, altura);
  // escribir sol
  cout << sol.first << ' ' << sol.second << '\n';
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}