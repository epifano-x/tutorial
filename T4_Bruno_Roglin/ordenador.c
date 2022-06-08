#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define para system("pause");

FILE *arquivo;

typedef struct arquivos {

    char nomedoarquivo[255];
    int *vetor;
    int *vetor2;
    int *vetor3;
    int tam;
    int Qtroca;

} registro;
registro strRegistro;


void gotoxy(int x, int y) {
    COORD c;
    c.X = x -1;
    c.Y = y -1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}


int menu() {

    int pos=0, lin=3, col=7,lim=16;
    int tecla;

    gotoxy(1,0);
    printf("%c",201);

    for(int i=0; i<22; i++) {
        printf("%c",205);
    }

    printf("%c\n",187);

    for(int i=0; i<lim+3; i++) {
        printf("%c                      %c\n",186,186);
    }

    printf("%c",200,188);

    for(int i=0; i<22; i++) {
        printf("%c",205);
    }

    printf("%c\n",188);

    if(strRegistro.tam!=0) {
        gotoxy(1,lim+6);
        printf("%c",201);

        for(int i=0; i<22; i++) {
            printf("%c",205);
        }
        printf("%c\n",187);
        printf("%c                      %c",186,186);

        gotoxy(2,lim+7);

        printf("%s\n",strRegistro.nomedoarquivo);
        printf("%c",200,188);

        for(int i=0; i<22; i++) {
            printf("%c",205);
        }

        printf("%c\n",188);
    }

    do {
        gotoxy(col,lin);
        printf("    Arquivo");

        gotoxy(col,lin+2);
        printf("   Bubble Sort");

        gotoxy(col,lin+4);
        printf("Insertion Sort");

        gotoxy(col,lin+6);
        printf("   Shelll Sort");

        gotoxy(col,lin+8);
        printf("Selection Sort");

        gotoxy(col,lin+10);
        printf("    Quick Sort");

        gotoxy(col,lin+12);
        printf("    Merge Sort");

        gotoxy(col,lin+14);
        printf("     Heap Sort");

        gotoxy(col,lin+16);
        printf("    Radix Sort");

        gotoxy(col-4,lin+pos);
        printf("->");

        tecla=getch();

        switch(tecla) {
        case 80:
            gotoxy(col-4,lin+pos);
            printf("  ");
            if(pos<lim) pos+=2;
            break;

        case 72:
            gotoxy(col-4,lin+pos);
            printf("  ");
            if(pos>0) pos-=2;
            break;

        case 13:
            system("cls");
            return pos;

        case VK_ESCAPE:
            system("cls");
            return 404;
        }
    }
    while(1);


}


int menuArquivo(){

    int pos=0, lin=3, col=7,lim=2;
    int tecla;
    gotoxy(1,0);
    printf("%c",201);

    for(int i=0; i<22; i++) {
        printf("%c",205);
    }

    printf("%c\n",187);

    for(int i=0; i<lim+3; i++) {
        printf("%c                      %c\n",186,186);
    }

    printf("%c",200,188);

    for(int i=0; i<22; i++) {
        printf("%c",205);
    }
    printf("%c\n",188);

    if(strRegistro.tam!=0) {
        gotoxy(1,lim+6);
        printf("%c",201);

        for(int i=0; i<22; i++){
            printf("%c",205);
        }
        printf("%c\n",187);
        printf("%c                      %c",186,186);

        gotoxy(2,lim+7);

        printf("%s\n",strRegistro.nomedoarquivo);
        printf("%c",200,188);

        for(int i=0; i<22; i++){
            printf("%c",205);
        }
        printf("%c\n",188);
    }
    do {
        gotoxy(col,lin);
        printf("Abrir Arquivo");

        gotoxy(col,lin+2);
        printf("Gerar Arquivo");

        gotoxy(col-4,lin+pos);
        printf("->");

        tecla=getch();

        switch(tecla){

        case 80:
            gotoxy(col-4,lin+pos);
            printf("  ");
            if(pos<lim) pos+=2;
            break;

        case 72:
            gotoxy(col-4,lin+pos);
            printf("  ");
            if(pos>0) pos-=2;
            break;

        case 13:
            system("cls");
            return pos;

        case VK_ESCAPE:
            system("cls");
            return 404;
        }
    }
    while(1);


}


void abrir_arquivo() {

    int aux = 0;

    strRegistro.tam = 0;
    char c;
    int t = 0;

    do {
        printf("===========================\n");
        printf("INFORME O NOME DO ARQUIVO: ");
        gotoxy(1,3);
        printf("===========================");
        gotoxy(28,2);
        scanf("%s",&strRegistro.nomedoarquivo);
        strcat(strRegistro.nomedoarquivo, ".txt");
        arquivo = fopen(strRegistro.nomedoarquivo, "r");

        if (arquivo == NULL) {
            system("cls");
            printf("Problemas na abertura do arquivo\n");
            Sleep(1000);
        }
        else {
            aux=1;
        }
        system("cls");
    }
    while(aux==0);
    while(fread (&c, sizeof(char), 1, arquivo)) {
        if(c == '\n') {
            strRegistro.tam++;
        }
    }

    strRegistro.vetor=malloc(strRegistro.tam*sizeof(int));
    strRegistro.vetor2=malloc(strRegistro.tam*sizeof(int));
    strRegistro.vetor3=malloc(strRegistro.tam*sizeof(int));
    rewind(arquivo);

    while(fscanf(arquivo,"%d",&strRegistro.vetor[t])!= EOF) {
        t++;
    }

    for(t=0; t<=strRegistro.tam; t++) {
        strRegistro.vetor2[t]=strRegistro.vetor[t];
    }

    system("cls");
    fclose(arquivo);
}


void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(){
    int i, j;

    clock_t end,start;
    printf("Processando . . .");

    start=clock();
    for (i = 0; i < strRegistro.tam-1; i++)

        for (j = 0; j < strRegistro.tam-i-1; j++)
            if (strRegistro.vetor[j] > strRegistro.vetor[j+1])
                swap(&strRegistro.vetor[j], &strRegistro.vetor[j+1]);
    end = clock();

    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Bubble Sort\n",strRegistro.nomedoarquivo);
    para

}

void insertionSort(){
    int i, key, j;

    clock_t end,start;
    printf("Processando . . .");
    start = clock();

    for (i = 1; i < strRegistro.tam ; i++){
        key = strRegistro.vetor[i];
        j = i - 1;

        while (j >= 0 && strRegistro.vetor[j] > key){
            strRegistro.vetor[j + 1] = strRegistro.vetor[j];
            j = j - 1;
        }
        strRegistro.vetor[j + 1] = key;
    }
    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Insertion Sort\n",strRegistro.nomedoarquivo);
    para
}

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(strRegistro.vetor[l1] <= strRegistro.vetor[l2])
         strRegistro.vetor3[i] = strRegistro.vetor[l1++];
      else
         strRegistro.vetor3[i] = strRegistro.vetor[l2++];
   }

   while(l1 <= mid)
      strRegistro.vetor3[i++] = strRegistro.vetor[l1++];

   while(l2 <= high)
      strRegistro.vetor3[i++] = strRegistro.vetor[l2++];

   for(i = low; i <= high; i++)
      strRegistro.vetor[i] = strRegistro.vetor3[i];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

void mergeS(){

    clock_t end,start;
    printf("Processando . . .");
    start = clock();
    sort(0,strRegistro.tam);
    end = clock();

    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Merge Sort\n",strRegistro.nomedoarquivo);
   para
}

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;


    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }


void heapSort() {
    clock_t end,start;
    printf("Processando . . .");
    start = clock();

    for (int i = strRegistro.tam / 2 - 1; i >= 0; i--)
      heapify(strRegistro.vetor, strRegistro.tam, i);


    for (int i = strRegistro.tam - 1; i >= 0; i--) {
      swap(&strRegistro.vetor[0], &strRegistro.vetor[i]);


      heapify(strRegistro.vetor, i, 0);
    }

    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Heap Sort\n",strRegistro.nomedoarquivo);
    para
  }


void radixsort() {
    int i;
    int *b;
    int maior = strRegistro.vetor[0];
    int exp = 1;
    clock_t end,start;
    printf("Processando . . .");
    start = clock();

    b = (int *)calloc(strRegistro.tam, sizeof(int));

    for (i = 0; i < strRegistro.tam; i++) {
        if (strRegistro.vetor[i] > maior)
    	    maior = strRegistro.vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < strRegistro.tam; i++)
    	    bucket[(strRegistro.vetor[i] / exp) % 10]++;

    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (i = strRegistro.tam - 1; i >= 0; i--)
    	    b[--bucket[(strRegistro.vetor[i] / exp) % 10]] = strRegistro.vetor[i];

    	for (i = 0; i < strRegistro.tam; i++)
    	    strRegistro.vetor[i] = b[i];
    	exp *= 10;
    }
    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Radix Sort\n",strRegistro.nomedoarquivo);
    para
    free(b);
}


void shellSort(){
    int i, j, value;
    int gap = 1;

    clock_t end,start;
    printf("Processando . . .");
    start = clock();

    while(gap < strRegistro.tam){
        gap = 3*gap+1;
    }

    while ( gap > 1){
        gap /= 3;

        for(i = gap; i < strRegistro.tam; i++){
            value = strRegistro.vetor[i];
            j = i - gap;

            while (j >= 0 && value < strRegistro.vetor[j]){
                strRegistro.vetor [j + gap] = strRegistro.vetor[j];
                j -= gap;
            }
            strRegistro.vetor [j + gap] = value;
        }
    }

    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Shell Sort\n",strRegistro.nomedoarquivo);
    para
}


void SelectionSort(){
    int i, j, min_idx;

    clock_t end,start;
    printf("Processando . . .");
    start = clock();

    for (i = 0; i < strRegistro.tam-1; i++){
        min_idx = i;

        for (j = i+1; j < strRegistro.tam; j++)

            if (strRegistro.vetor[j] < strRegistro.vetor[min_idx])
                min_idx = j;
        swap(&strRegistro.vetor[min_idx], &strRegistro.vetor[i]);
    }
    end = clock();
    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Selection Sort\n",strRegistro.nomedoarquivo);
    para
}


void _quickSort_(registro vetor, int inicio, int fim)
{
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = strRegistro.vetor[(fim + inicio) / 2];

    while (i <= j){

        while (strRegistro.vetor[i] < pivo && i < fim)
            i++;

        while (strRegistro.vetor[j] > pivo && j > inicio)
            j--;

        if (i <= j){
            aux = strRegistro.vetor[i];
            strRegistro.vetor[i] = strRegistro.vetor[j];
            strRegistro.vetor[j] = aux;
            i++;
            j--;
        }
    }
    if (j > inicio)
        _quickSort_(vetor, inicio, j + 1);

    if (i < fim)
        _quickSort_(vetor, i, fim);
}


void quickSort(registro vetor)
{
    int inicio = 0;
    int fim = strRegistro.tam - 1;

    clock_t end,start;
    printf("Processando . . .");
    start=clock();
    _quickSort_(vetor, inicio, fim);
    end = clock();

    system("cls");

    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
    printf("%s / Quick Sort\n",strRegistro.nomedoarquivo);
   para
}

void selecao(int op){
    int arq;

    switch (op){

        case 0:
            arq=menuArquivo();
            if(arq==2){
                system("gerar-arquivos\\gerar-arquivos.exe");
                system("cls");
                break;
            } else{
                if(arq==404)
                    break;
                else
                    abrir_arquivo();
            }
            break;

        case 2:
            if(strRegistro.tam==0){

            }else{
                bubbleSort();
            }
            system("cls");break;

        case 4:
            if(strRegistro.tam==0){
                break;
            }else{
                insertionSort();
            }
            system("cls");break;

        case 404: return 0;

        case 6:
            if(strRegistro.tam==0){
                break;
            } else{
                shellSort();
            }
            system("cls");break;

        case 8:
            if(strRegistro.tam==0){
                break;
            } else{
                SelectionSort();
            }
            system("cls");break;

        case 10:
            if(strRegistro.tam==0){
                break;
            } else{
                quickSort(strRegistro);
            }
            system("cls");break;

        case 12:
            if(strRegistro.tam==0){
                break;
            } else{
                mergeS();

            }
                system("cls");break;

        case 14:
            if(strRegistro.tam==0){
                break;
            } else{
                heapSort(strRegistro.vetor,strRegistro.tam);
            }
                system("cls");break;

        case 16:
            if(strRegistro.tam==0){
                break;
            } else{
                radixsort();

            }
                system("cls");break;
    }

    if(strRegistro.tam!=0){
        for(int t=0; t<=strRegistro.tam; t++){
            strRegistro.vetor[t]=strRegistro.vetor2[t];
        }
    }

}


main()
{
    int op;
    do{
        op=menu();

        if(op==404){
            break;
        }
        selecao(op);
    }
    while(1);
}
