/*Escrever um programa que:
Abra um arquivo de texto que contém um inteiro e uma string por linha, sendo que a primeira linha contém apenas um inteiro, que indica o número restante de linhas;
Defina uma estrutura para armazenar um inteiro e uma string; 
Armazene estes elementos em um vetor alocado dinamicamente do tipo definido pela estrutura; 
Imprima os elementos do vetor no formato:
[inteiro1, string1]
[inteiro2, string2]
...
[inteiroN, stringN] */

#include <stdio.h>
#include <stdlib.h>

struct vetor{
    int num;
    char string[50];
};


int main(){
    FILE *aqr;
    int quat_elem;
    int i = 0;
    char nome[30];

    //pede o nome do arquivo para abrir
    printf ("Digite o nome do arquivo: ");
    scanf ("%s", nome);
    
    //abre o arquivo para leitura
    aqr = fopen(nome, "r");
    //se houver erro na abertura
    if(aqr == NULL){
        printf ("erro ao ler o arquivo!");
        return 1;
    }

    //Le a primeria linha para saber o tamanho
    fscanf(aqr, "%d", &quat_elem);

    //aloca o vetor dinamicamente
    struct vetor *vetor = (struct vetor *)malloc(quat_elem * sizeof(struct vetor));
    //Se houver erro ao alocar
    if (vetor == NULL){
        printf("erro ao alocar memoria!");
        return 1;
    }

    // lê o arquivo e armazena no vetor
    while (fscanf(aqr, "%d %s", &vetor[i].num, vetor[i].string) != EOF){
        i++;
    }

    //imprime os elementos do vetor
    for (i = 0; i < quat_elem; i++){
        printf ("[%d %s]\n", vetor[i].num, vetor[i].string);
    }
    
}