// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const &v, int const cant)
{
  int sumaAct = v[0], puntMax = v[0];
  for (int i = 1; i < cant; ++i)
  {
    sumaAct += v[i];
    if (v[i] > puntMax)
      puntMax = v[i];
  }

  int sumaMax = sumaAct, pagIniMax = 0, pagIniAct = 0;
  bool esMayor = false;
  for (int i = cant; i < v.size(); ++i)
  {
    if (v[i] >= puntMax)
    {
      sumaAct -= v[pagIniAct];
      ++pagIniAct;
      sumaAct += v[i];
      esMayor = true;
    }
    else 
      esMayor = false;

    if (sumaAct >= sumaMax && esMayor)
    { // >= ya que queremos el mas avanzado => el ultimo
      pagIniMax = pagIniAct;
      sumaMax = sumaAct;
    }
  }
  return pagIniMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve cada caso de la entrada
bool resuelveCaso() 
{
    int numElem, L;
    std::cin >> numElem >> L;
    if (numElem == 0 && L == 0) return false;
    std::vector<int> v(numElem);
    for (int &n : v) std::cin >> n;
    
    // LLamada a la funcion que resuelve el problema
    int sol  = resolver(v, L);
    // Escribir el resultado
    cout << sol << '\n';

    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  while (resuelveCaso())
    ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif

  return 0;
}
