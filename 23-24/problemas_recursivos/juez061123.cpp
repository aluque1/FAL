#include <iostream>

using namespace std;

long long entretenidos(long long n)
{
    long long res = 0;
    int lsd = n % 10;
    long long aux = (n / 10) % 10;
    if (n < 10)
        res += n;
    else
        if(lsd != aux)
            res += 1 + entretenidos(n - 1);
        else
            res += entretenidos(n - 1);
    return res;
}

int main()
{

    long long n;
    while ((cin >> n) && n != -1)
    {
        cout << entretenidos(n) << endl;
    }
    return 0;
}