#include <iostream>

using namespace std;

int v [1000000];

int buscarIz(int altura, int ini, int fin){
  if(ini >= fin) return ini; // vector vacio
  else if(ini + 1 == fin) return ini; // vector 1 elem
  else {
    int mitad  = (ini + fin - 1) / 2;
    if(altura < v[mitad]) return buscarIz(altura, ini, mitad + 1); // buscamos por la izquierda
    else return buscarIz(altura, mitad + 1, fin); // buscamos por la derecha
  }
}

int buscarDr(int altura, int ini, int fin){
  if(ini >= fin) return ini; // vector vacio
  else if(ini + 1 == fin) return ini; // vector 1 elem
  else {
    int mitad  = (ini + fin) / 2;
    if(altura < v[mitad]) return buscarDr(altura, ini, mitad); // buscamos por la izquierda
    else return buscarDr(altura, mitad, fin); // buscamos por la derecha
  }
}


bool resuelveCaso(){
  int n, altura;
  cin >> n >> altura;
  if(!cin) return false;
  
  for(int i = 0; i < n; ++i)
    cin >> v[i];

  int posIz, posDr;

  posIz = buscarIz(altura, 0, n);

  if(posIz == n || v[posIz] != altura) // no se ha encontrado el elemento
    cout << "NO EXISTE\n";
  else // buscamos el lado derecho
  {
    posDr = buscarDr(altura, 0, n);
    if(posDr == posIz) cout << posIz << endl;// tienen la misma posicion <---> solo hay una instancia
    else cout << posIz << " " << posDr << endl; // hay varias instancias
  }
  return true;
}

int main(){
  while(resuelveCaso()){}
  return 0;
}