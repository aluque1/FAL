#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resuelveCaso()
{
}

int main()
{
// Para la entrada por fichero .
#ifndef DOMJUDGE
  std ::ifstream in("datos.txt");
  auto cinbuf = std ::cin.rdbuf(in.rdbuf());
#endif

  //Entrada con numero de casos
  int numCasos;
  cin >> numCasos;
  for(int i = 0; i < numCasos; ++i)
    resuelveCaso();
    
// Para restablecer entrada .
#ifndef DOMJUDGE
  std ::cin.rdbuf(cinbuf);
  // system(" PAUSE ");
#endif
  return 0;
}
