#include <stdio.h>
#include <time.h>
#include <stdlib.h>


main(){

    srand (time(NULL));

    int n;
    FILE *ordenado, *invertido, *randomico;
    int tamanho, x;
    char nomeLista[255];

    printf("Informe o tamanho do arquivo: ");
    scanf("%d", &tamanho);

    sprintf(nomeLista, "arqOrdenado%07d.txt", tamanho);

    ordenado = fopen(nomeLista, "w");
    for (x = 1;x <= tamanho;x++){
    fprintf(ordenado, "%d\n", x);
    }
    fclose(ordenado);

    sprintf(nomeLista, "arqInvertido%07d.txt", tamanho);

    invertido = fopen(nomeLista, "w");

    for (x = tamanho;x >= 1;x--){
    fprintf(invertido, "%d\n", x);
    }
    fclose(invertido);

    sprintf(nomeLista, "arqAleatorio%07d.txt", tamanho);

    randomico = fopen(nomeLista, "w");

    for (x = tamanho;x >= 1;x--){
    n= rand()%tamanho+1;
    fprintf(randomico, "%d\n", n);
    }
    fclose(randomico);
}
