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
  int sumaAct = v[0];
  for(int i = 1; i < cant; ++i)
    sumaAct += v[i];
  
  int sumaMax = sumaAct, pagIniAct = 0, pagIniMax = 0;

  for(int i = cant; i < v.size(); ++i){
    sumaAct -= v[pagIniAct];
    ++pagIniAct;
    sumaAct += v[i];
    if(sumaAct >= sumaMax){ // >= ya que queremos el mas avanzado => el ultimo
      pagIniMax = pagIniAct;
      sumaMax = sumaAct;
    }
  }

  return pagIniMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  int pag, cant;
  cin >> pag >> cant;
  if (pag == 0 && cant == 0)
    return false;

  vector<int> v(pag);
  for (int &elem : v)
    cin >> elem;

  int sol = resolver(v, cant);
  
  // escribir sol
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
