/*Escrever um programa que:

    ◦ Abra e leia um arquivo de texto que contém um inteiro por linha, 
    sendo que o primeiro inteiro indica o número restante de elementos;

    ◦ Armazene estes inteiros em um vetor alocado dinamicamente;

    ◦ Imprima os elementos do vetor no formato {e1, e2, ..., eN};
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *aqr;
    int *vetor; 
    int quat_num;
    int i = 0;

    //Abre o arquivo para leitura
    aqr = fopen("ex1.txt", "r");
    
    //Se houver erro na abertura
    if (aqr == NULL){
        printf("Erro ao ler o arquivo!");
        return 1;
    }

    //Lê a primeira linha até o \n, no formato (int, char, etc...) especificado, e retorna para a variavel.
    fscanf(aqr, "%d", &quat_num);

    //Aloca dinamicamente o vetor
    vetor = (int *)malloc(quat_num * sizeof(int));
    if (vetor == NULL){
        printf ("erro ao alocar memória!");
        return 1;
    }
    
    //Ler o arquivo e armazena no vetor
    while (fscanf(aqr, "%d", &vetor[i]) != EOF){
        i++;
    }
    
    // Imprimir os elementos do vetor
    printf("{");
    for (i = 0; i < quat_num; i++) {
        printf("%d", vetor[i]);
        if (i != quat_num - 1){
            printf (", ");
        }
        
    }
    printf("}\n");


    free (vetor);
    fclose(aqr);
    return 0;
}