#include <iostream>

using namespace std;

// Ejercicio 222 Serie de potencias
// Resuelto en la funcion resuelve
/* 
    { Pre: 1 <= x <= 100 ^ 0 <= n <= 1000000 }
    { Post: ret = ( Sumatorio i : 0 <= i <= n : x^i ) mod 1000007 }
    { Coste: O(n) siendo a el exponente de la serie }
 */

bool resolver() {

	short int x;
	int n;
	cin >> x >> n;

	if (!cin) return false;

	int suma_acu = 1, potencia_acu = 1;

	for (int i = 1; i <= n; ++i) {
		potencia_acu = (potencia_acu * x)%1000007;
		suma_acu = (suma_acu + potencia_acu)%1000007;
	}
	
	cout << suma_acu << '\n';

	return true;
}

int main() {
	while (resolver());

	return 0;
}