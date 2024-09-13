#include <iostream>

using namespace std;

int v[200000];

bool resuelve()
{
  int num_partidos;
  cin >> num_partidos;
  
  if(!cin) return false;

  for (int i = 0; i < num_partidos; i++)
    cin >> v[i];

  int cont_sin = -1, racha_act = 0, racha_max = 0, num_rachas = 0;

  for(int i = 0; i < num_partidos; ++i){
    if(v[i] > 0){
      ++racha_act;
      if(racha_act == racha_max){
        ++num_rachas;
        cont_sin = i;
      }
      else if(racha_act > racha_max){
        racha_max = racha_act;
        num_rachas = 1;
        cont_sin = i;
      }
    } else {
      racha_act = 0;
    }
  }

  cout << racha_max << " " << num_rachas << " " << num_partidos - cont_sin - 1 << endl;
}

int main(int argc, char const *argv[])
{
  while(resuelve()){}

  return 0;
}