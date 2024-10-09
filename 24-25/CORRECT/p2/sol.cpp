#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resuelveCaso(int numElems)
{
  string nacionalidad;
  int year;
  bool encontrado = false;
  cin >> nacionalidad;

  vector<string> v(numElems);

  for (string &i : v)
    cin >> i;

  year = v.size() - 1;
  while(year >= 0 && !encontrado){
    if(v[year] == nacionalidad)
      encontrado = true;
    else
      --year;
  }

  cout << (year < 0 ? "NUNCA" : to_string(numElems - year)) << endl;
}

int main()
{
// Para la entrada por fichero .
#ifndef DOMJUDGE
  std ::ifstream in("datos.txt");
  auto cinbuf = std ::cin.rdbuf(in.rdbuf());
#endif

  // Entrada con centinela
  int numElems;
  while (cin >> numElems && numElems != 0)
    resuelveCaso(numElems);

// Para restablecer entrada .
#ifndef DOMJUDGE
  std ::cin.rdbuf(cinbuf);
  // system(" PAUSE ");
#endif
  return 0;
}
