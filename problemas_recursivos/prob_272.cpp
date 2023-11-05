#include <iostream>

using namespace std;

// Problema 272 - Tres dedos en cada mano
// Resuelto en la funcion base6(int n)

int base6(int n)
{
    int base6_ans = 0;
    if (n < 6)
        base6_ans += n;
    else
        base6_ans += (base6(n / 6)) * 10 + n % 6;

    return base6_ans;
}

int main(int argc, char const *argv[])
{
    int n;
    int num;
    cin >> n;
    while (n > 0)
    {
        cin >> num;
        cout << base6(num) << '\n';
        --n;
    }
    return 0;
}