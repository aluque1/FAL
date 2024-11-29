// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

using t_matrix = vector<vector<int>>;

bool esValida(vector<int> marca_supermecados, int k, vector<int> &sol,  vector<bool> marca_productos) {
    if (marca_productos[k]) return false;
    if (marca_supermecados[sol[k]] >= 3) return false;
    else return true;
}

// función que resuelve el problema
bool hacer_compra(t_matrix const &precios,int num_supermercados,int num_productos, int k, vector<int> &sol, vector<int> &marca_supermercados, vector<bool> &marca_productos, int &mejor_precio, int &precio_act, vector<int> const &minimos_acum) {
    bool haySol = false;
    for (int i = 0; i < num_supermercados; ++i) {
        sol[k] = i;
        if (esValida(marca_supermercados, k, sol, marca_productos)) {
            precio_act += precios[i][k];
            marca_productos[k] = true;
            ++marca_supermercados[i];
            if (k = num_productos - 1) {
                haySol = true;
                if (precio_act > mejor_precio) // es una solucion mejor a la que teniamos
                    mejor_precio = precio_act;
            }
            else {
                if (minimos_acum[k + 1] + precio_act < mejor_precio) // es una solucion viable
                    hacer_compra(precios, num_supermercados, num_productos, k + 1, sol, marca_supermercados, marca_productos, mejor_precio, precio_act, minimos_acum);
            }
            precio_act -= precios[i][k];
            marca_productos[k] = false;
            --marca_supermercados[i];
        }
    }
    return haySol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num_supermercados, num_productos;
    cin >> num_supermercados >> num_productos;
    t_matrix precios(num_supermercados, vector<int>(num_productos));

    for (int i = 0; i < num_supermercados; ++i) {
        for (int j = 0; j < num_productos; ++j) {
            cin >> precios[i][j];
        }
    }

    vector<int> sol(num_productos);
    vector<int> marca_supermercados(num_supermercados);
    vector<bool> marca_productos(num_productos);
    vector<int> minimos(num_productos);

    int mejor_precio = numeric_limits<int>::max();
    int precio_act = 0;
    minimos[0] = precios[0][0];

    for (int j = 0; j < num_productos; ++j) {
        minimos[j] = precios[0][j];
        for (int i = 0; i < num_supermercados; ++i) {
            if (minimos[j] > precios[i][j])
                minimos[j] = precios[i][j];
        }
    }

    vector<int> minimos_acum(num_productos, 0);
    minimos_acum[minimos.size() - 1] = minimos[minimos.size() - 1];
    
    for (int i = minimos_acum.size() - 2 ; i > -1; --i)
        minimos_acum[i] += minimos[i] + minimos_acum[i + 1];

    bool existe_sol = hacer_compra(precios, num_supermercados, num_productos, 0, sol, marca_supermercados, marca_productos, mejor_precio, precio_act, minimos_acum);

    // escribir sol
    existe_sol ? cout << mejor_precio << '\n' : cout << "Sin solucion factible\n";


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
