#include <iostream>
using namespace std;

// Problema 570 - DNI incompleto
// Resuelto en la funcion dni(string prefix, int n)

string transformar = "TRWAGMYFPDXBNJZSQVHLCKE";

void dni(
    /* Descripcion problema */
    string numero,
    string letra,
    int length,
    /* Datos solucion parcial */
    string solParcial,
    int k
    )
{
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string dni_incompleto = "";
        // Rellenamos descripcion problema
        cin >> dni_incompleto;
        string letra = dni_incompleto.substr(8, 1);
        dni_incompleto = dni_incompleto.substr(0, 8);
        int length = dni_incompleto.length();

        dni(dni_incompleto, letra, length, "", 0);
    }

    return 0;
}
