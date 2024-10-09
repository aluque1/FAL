// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const &v, int desnivel)
{
    bool apta = true;
    int desnivelAcum = 0;
    int prev = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > prev)
        {
            desnivelAcum += (v[i] - prev);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int desnivel, numElems;
    cin >> desnivel, numElems;

    if (!std::cin)
        return false;

    vector<int> v(numElems, desnivel);

    for (int &elem : v)
        cin >> elem;

    bool sol = resolver(v);

    // escribir sol
    cout << (sol ? "APTO\n" : "NO APTO\n");

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
    system("PAUSE");
#endif

    return 0;
}