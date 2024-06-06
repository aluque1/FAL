#include <iostream>

using namespace std;

// Ejercicio 250 El desgaste de los bombines
// Resuelto en la funcion resuelve()

int v[1000000];

/*  
    { Pre: 0 < n <= longitud(v) <= 1000000 }
    { Post: }
    { Coste: O(n) siendo n el numero de elementos del vector v }
*/
bool resuelve() 
{
  long num_bombines, pos;
  long long desgaste_d, desgaste_l, dif_desgaste_actual, desgaste_sin_cerrajero, min_dif_desgaste;
  cin >> num_bombines;
  if(num_bombines == 0) return false;

  for(int i = 0; i < num_bombines; i++){
    cin >> v[i];
    desgaste_d += v[i];
  }

  if(desgaste_d == 0) { // En este caso la diferencia del desgaste es 0 => no tiene que venir el cerrajero
    cout << 0 << endl;
  } else {
    desgaste_sin_cerrajero = desgaste_d;
    desgaste_d *= -1; 
    desgaste_l = 0;
    pos = -1;
    min_dif_desgaste = desgaste_sin_cerrajero;

    for(int i = 0; i < num_bombines; ++i){
      desgaste_d += v[i];
      desgaste_l += v[i];
      dif_desgaste_actual = abs(desgaste_d + desgaste_l);
      if(dif_desgaste_actual < min_dif_desgaste){
        min_dif_desgaste = dif_desgaste_actual;
        pos = i;
      }
    }

    if(desgaste_sin_cerrajero < min_dif_desgaste){ // por si era mejor no llamar al cerrajero
      cout << 0 << endl;
    } else {
      cout << pos + 1 << endl;
    }
  }

  return true;
}

int main(int argc, char const *argv[])
{
  while(resuelve()){}

  return 0;
}
