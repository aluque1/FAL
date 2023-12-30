#include <iostream>

using namespace std;

// problema examen vuelta atras de piratas
void asignaMonedas(
    /* Descripcion del problema */
    int valorMonedas[],
    int n,
    int minimoMonedas[2],
    /* Solucion parcial */
    int k,
    int solParcial[], // solParcial[i] = pirata que se lleva la moneda
    /* Marcaje */
    int gananciaParcial[2], // cuanto valor tiene las bolsas ya asignadas a pirata1, pirata2 equivalente gananciaParcial[0], gananciaParcial[1]
    int pendientes[2],      // cuantas monedas quedan por repartir a cada pirata
    /* Solucion optima */
    int &minDiff,
    int &cuantas)
{
    if (k == n)
    { // ya he tomado todas las soluciones posibles
        if (abs(gananciaParcial[1] - gananciaParcial[0]) == minDiff)
            ++cuantas;
        else
        {
            minDiff == abs(gananciaParcial[1] - gananciaParcial[0]);
            cuantas = 1;
        }
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        // asignar moneda al pirata 1
        int otro = (i ^ 1); // == if i == 0 otro = 1, else otro = 0
        /*
            if(i == 0)
                otro = 1;
            else
                otro = 0;
         */
        // Es prometedora ?
        if ((pendientes[otro] > 0) &&
            (n - k + 1) < pendientes[otro])
            continue;

        // Podemos igualar o mejorar la solucion optima ?
        if (0) // requiere marcaje de valor pendiente
            continue;

        solParcial[k] = i;
        gananciaParcial += valorMonedas[i];
        --pendientes[i];
        asignaMonedas(
            valorMonedas, n, minimoMonedas,
            k + 1, solParcial,
            gananciaParcial, pendientes,
            minDiff, cuantas);
        ++pendientes;
        gananciaParcial[i] -= valorMonedas[i];
    }
}

// problema recursivo examen

/*
    Descripcion del problema:
    nos dan un numero n que siempre va a tener numero par de digitos
    y tenemos que calcular un codigo secreto, esto se hace asi

    codigo secreto es 
        si la posicion de digito es par: 
            3*digito + min digitos a su derecha.
        si la posicion de digito es impar:
            2*digito + max numeros a su izquierda.
*/
int calcula(int n){
    int dummy1, dummy2;     
    return calculaCodigo(n, 10, dummy1, dummy2);
                        /*   ^ 
                             +---  Nunca va a haber un digito mas grande que esto, se usa como
                             un limite "infinito" */
}

int calculaCodigo(int n, int aSumarEnImpares, int &numDigitos, int &maxDigito)
{
    // Caso base
    if (n < 10)
    { // posicion 1 que es impar
        numDigitos = 1;
        maxDigito = n;
        return 3 * n + aSumarEnImpares;
    }
    // Caso Recursivo
    int d = n % 10;
    int ret = calculaCodigo(n / 10, min(aSumarEnImpares, d), numDigitos, maxDigito);

    if (numDigitos & 2 == 0)
        // pos par
        ret += 3 * d * aSumarEnImpares;
    else
        // pos impar
        ret += 2 * d + maxDigito;

    ++numDigitos;
    maxDigito = max(maxDigito, d);

    return ret;
}