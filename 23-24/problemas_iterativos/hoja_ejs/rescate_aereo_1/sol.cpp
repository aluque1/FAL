#include <iostream>

using namespace std;

int v[100000];

void resuelve_caso(){
  int n, t;

  cin >> n >> t;

  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }

  int tramo_max = 0, tramo_act = 0, pos_ini_max = 0, pos_ini_act = 0;

  for(int i = 0; i < n; ++i){
    if(v[i] > t){
      if(tramo_act == 0)
        pos_ini_act = i;
      ++tramo_act;
      if(tramo_act > tramo_max){
        tramo_max = tramo_act;
        pos_ini_max = pos_ini_act;
      }
    } else
      tramo_act = 0;
  }
  cout << pos_ini_max << " " << pos_ini_max + tramo_max - 1 << endl;
}

int main(int argc, char const *argv[])
{
  int num_casos;
  cin >> num_casos;
  for(int i = 0; i < num_casos; ++i)
    resuelve_caso();  
  return 0;
}
