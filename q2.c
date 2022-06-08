#include<stdio.h>

int fib(int n)
{
    // Declara um array para armazenar os numeros do Fibonacci
    int f[n+2];
    int i;

    //"ante-primeiro" e primeiro numero da serie sao 0 e 1
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        // Adiciona os ultimos 2 numeros da serie e armazena
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main ()
{
    int n = 11;
    printf("%d", fib(n));
    getchar();
    return 0;
}
