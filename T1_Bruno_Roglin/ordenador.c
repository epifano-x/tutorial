#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
FILE *arquivo;
 
typedef struct arquivos{

    int *vetor;
    int tamanho;
    int Qtroca;

}registro;
registro strRegistro;

void gotoxy(int x, int y){
    COORD ponto;
    ponto.X = x-1;
    ponto.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ponto);
}


int menu(){

int pos = 0, lin = 3, col = 7;

    int tecla;

    gotoxy(1,lin-2);
    printf("+----------------------+\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("+----------------------+\n");

    do {
        gotoxy(col,lin); printf("Bubble Sort");
        gotoxy(col,lin+2); printf("Insertion Sort");
        gotoxy(col-4,lin+pos); printf("->");
        tecla=getch();

        switch(tecla) {
            case 80:
                gotoxy(col-4,lin+pos); printf("  ");
                if(pos < 2) pos += 2;
                break;

            case 72:
                gotoxy(col-4,lin+pos); printf("  ");
                if(pos > 0) pos -= 2;
                break;

            case 13: system("cls");
                return pos;

            case VK_ESCAPE: system("cls");
                return 404;
        }
    } while(1);


}

void arquivoAbrir()
{
    int auxiliar = 0;
    char arquivoNome[255];
    strRegistro.tamanho = 0;
    char c;
    int t = 0;

    do{
    printf("===================================\n");
    printf("NOME DO ARQUIVO QUE SERA ORDENADO:          \n");
    printf("===================================\n");
    gotoxy(45,2);
    scanf("%s",&arquivoNome);
    arquivo = fopen(arquivoNome, "r");

    if (arquivo == NULL)
    {
        system("cls");
        printf("Nome de arquivo errado ou inexistente.");
        Sleep(600);
    }else{
            auxiliar = 1;
        }

    system("cls");
    }while(auxiliar == 0);

    while(fread (&c, sizeof(char), 1, arquivo))
    {
        if(c == '\n')
        {
            strRegistro.tamanho++;
        }
    }

    strRegistro.vetor = malloc(strRegistro.tamanho * sizeof(int));
    rewind(arquivo);

    while(fscanf(arquivo, "%d", &strRegistro.vetor[t])!= EOF)
    {
        t++;
    }

    system("cls");
    fclose(arquivo);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort()
{
    int i, j;
    clock_t end, start;
    printf("Processando . . . ");
    start = clock();

    for (i = 0; i < strRegistro.tamanho-1; i++)

    for (j = 0; j < strRegistro.tamanho-i-1; j++)
        if (strRegistro.vetor[j] > strRegistro.vetor[j+1])
            swap(&strRegistro.vetor[j], &strRegistro.vetor[j+1]);

    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start) / (double)(CLOCKS_PER_SEC));
    system("pause");
}

void insertionSort()
{
    int i, chave, j;

    clock_t end, start;
    printf("Processando . . . ");
    start = clock();

    for (i = 1; i < strRegistro.tamanho ; i++)
    {
        chave = strRegistro.vetor[i];
        j = i - 1;

        while (j >= 0 && strRegistro.vetor[j] > chave)
        {
            strRegistro.vetor[j + 1] = strRegistro.vetor[j];
            j = j - 1;
        }
        strRegistro.vetor[j + 1] = chave;
    }

    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start) / (double)(CLOCKS_PER_SEC));
    system("pause");
}


void selecao(int operacao)
{
    switch (operacao){

        case 0:
            bubbleSort();
            system("cls");
            break;

        case 2:
            insertionSort();
            system("cls");
            break;

        case 404:return 0;
    }
}


main(){
    int operacao;

    do
    {
        arquivoAbrir();
        operacao = menu();
        selecao(operacao);
    }while(1);
}
