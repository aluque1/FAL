#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int x;
  std::cout << "Introduzca un numero\n";
  cin >> x;
  if (x < 5)
    cout << "x es menor que 5";
  else
    cout << "x es mayor o igual que 5";
  return 0;
}
