// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const &v, int const &desnivel)
{
    bool posible = true;
    int i = 0, j = 0;

    while (j < v.size() - 1 && posible)
    {
        if (v[j + 1] > v[j]) // Si el j + 1 es mayor al anterior, increntamos j
            ++j;
        else
        {
            if (i == j) // Si i y j estan en el mismo punto, incrementamos j
                ++j;
            ++i; // Incrementamos i
        }
        if (v[j] - v[i] > desnivel) // Si el la diferencia de los puntos es mayor al desnivel permitido => false
            posible = false;
    }
    return posible;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int desnivel, numElems;
    cin >> desnivel >> numElems;

    if (!std::cin)
        return false;

    vector<int> v(numElems, desnivel);

    for (int &elem : v)
        cin >> elem;

    bool sol = resolver(v, desnivel);

    // escribir sol
    cout << (sol ? "APTA\n" : "NO APTA\n");

    return true;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif

    return 0;
}