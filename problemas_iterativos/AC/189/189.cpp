#include <iostream>
#include <algorithm>

using namespace std;

int v[1000000];

/*
    { Pre: 1 <= n <= longitud(v) <= 1000000 }
    { Post:  }
    { Coste: O(n) } 
*/
bool resuelve_caso(){
  int num_pasajeros, num_acciones, valor_accion;
  string accion;
  cin >> num_pasajeros;
  if(num_pasajeros == 0) return false;

  for(int i = 0; i < num_pasajeros; i++){
    cin >> v[i];
  }

  cin >> num_acciones;
  
  for(int i = 0; i < num_acciones; i++){
    cin >> accion >> valor_accion;

    if(accion == "EMBARQUE"){
      int por_embarcar = 0;
      for(int j = 0; j < num_pasajeros; ++j){
        if(v[j] != valor_accion){
          v[por_embarcar] = v[j];
          ++por_embarcar;
        }
      }
      num_pasajeros = por_embarcar;
      cout << num_pasajeros << endl;
    }
    else if (accion == "CONSULTA" )
      cout << v[valor_accion-1] << endl;
  }

  cout << "*" << endl;
  return true;
}

int main()
{
  while(resuelve_caso()){}
  return 0;
}