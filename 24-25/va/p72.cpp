// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const &v, int sum, int const M, int k) {
    if (k == v.size()){ // caso base hemos recorrido todo el vector
        if (sum == M) return true;
        else return false;
    }
    if (resolver(v, sum + v[k], M, k + 1)) // Sumamos el siguiente numero
        return true;
    if (resolver(v, sum - v[k], M, k + 1)) // Restamos el siguiente numero
        return true;

    /*
    * para la poda podemos usar un vector de lo que nos queda por sumar, es decir de los valores a la derecha de K
    * 
    * Si suma + suma_acum[k] >= M && else suma - suma_acum[k] <= M podemos seguir con la solucion
    */

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int wanted_sum, num_elems;

    cin >> wanted_sum >> num_elems;

    vector<int> v(num_elems);

    for (int& elem : v)
        cin >> elem;

    // como el primer numero siempre se suma podemos empezar ya con el primer numero sumado por lo tanto empezamos con k = 1
    bool sol = resolver(v, v[0], wanted_sum, 1);

    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
