// Nombre del alumno Alejandro Luque Villegas
// Usuario del Juez A75

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
/*
    PRE : { 0 <= n  < v.size() ^ ordenadoEstrictamente(v)
            donde ordenado(v) = (P.t. i, j : 0 <= i < j < v.size() : v[i] < v[j]) }
*/
vector<int> resolver(vector<int> const &v1, vector<int> const &v2)
{
    vector<int> sol;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            sol.push_back(v1[i]);
            ++i;
        }
        else if (v1[i] > v2[j])
        {
            sol.push_back(v2[j]);
            ++j;
        }
        else // segun el enunciado si son iguales solo se mete uno de los 2
        {
            sol.push_back(v1[i]);
            ++i;
            ++j;
        }
    }

    while (i < v1.size())
    { // quedan elems en primero
        sol.push_back(v1[i]);
        ++i;
    }

    while (j < v2.size())
    { // quedan elems en segundo
        sol.push_back(v2[j]);
        ++j;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int numElems1, numElems2;
    cin >> numElems1 >> numElems2;

    vector<int> v1(numElems1);
    vector<int> v2(numElems2);

    for (int &elem : v1)
        cin >> elem;

    for (int &elem : v2)
        cin >> elem;

    vector<int> sol = resolver(v1, v2);
    // escribir sol
    for (int i = 0; i < sol.size(); ++i)
        cout << sol[i] << ' ';
    cout << '\n';
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
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