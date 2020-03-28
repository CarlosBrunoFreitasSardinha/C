/*
Implemente um programa em C, utilizando alocação dinâmica com ponteiros de memória,
que leia duas matrizes (de dimensões definidas pelo usuário), faça a soma delas e
armazene o resultado em uma terceira matriz.
Nome do arquivo: matrizes.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int col=1,lin=1,i,j;
    int **ma=NULL,**ma2=NULL,**ma3=NULL;
    
    printf("Quantas colunas tem essa tabela: ");
    scanf("%d",&col);
   
    printf("Quantas linhas tem essa tabela: ");
    scanf("%d",&lin);
     ma=(int**)malloc(col* sizeof(int*));
     ma3=(int**)malloc(col* sizeof(int*));
     ma2=(int**)malloc(col* sizeof(int*));
     
    for (i=0;i<lin;i++){
        ma[i] =(int*)malloc(col* sizeof(int*));
        ma2[i]=(int*)malloc(col* sizeof(int*));
        ma3[i]=(int*)malloc(col* sizeof(int*));
     }
     printf("\n\n Informe os valores da 1§ matris.\n");
     for (i=0;i<lin;i++){
         for (j=0;j<col;j++){
             printf("\n\t Digite o %d§ valor da coluna %d: ",j+1,i+1);
             scanf("%d",&ma[i][j]);
          }
      }
     printf("\n\n Informe os valores da 2§ matris.\n");
     for (i=0;i<lin;i++){
         for (j=0;j<col;j++){
             printf("\n\t Digite o %d§ valor da coluna %d: ",j+1,i+1);
             scanf("%d",&ma2[i][j]);
          }
      }
      system("cls");
     printf("\n\n os valores da 1§ matris.\n");
     for (i=0;i<lin;i++){
         printf("\n\n");
         for (j=0;j<col;j++){
             printf("| %d |",ma[i][j]);
          }
      }
      
      printf("\n\n os valores da 2§ matris.\n");
      printf("\t\t\t");
      for (i=0;i<lin;i++){
         printf("\n\n");
         for (j=0;j<col;j++){
             printf("| %d |",ma2[i][j]);
          }
      }
     printf("\n\n A soma dos valores das matris. e\n");
      for (i=0;i<lin;i++){
         printf("\n\n");
         for (j=0;j<col;j++){
             ma3[i][j]=ma[i][j]+ma2[i][j];
             printf("| %d |",ma3[i][j]);
          }
      }
    for (i=0;i<col;i++){
        free(ma3[i]);
        free(ma2[i]);
        free(ma[i]);
        }
        printf("\n\n");
    system("PAUSE");
    }
