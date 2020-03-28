/*
Implementar um programa em C, utilizando alocação dinâmica com ponteiros de memória,
que armazene os seguintes dados sobre as operações de uma locadora de veículos (o
número de operações é determinado pelo usuário):
a) Nome do cliente;
b) modelo do carro;
c) quilometragem de saída;
d) quilometragem de chegada;
e) valor cobrado por quilômetro rodado;
f) quilometragem rodada (calcular);
g) valor a ser cobrado (calcular).
Ao final, deve-se calcular a média de quilometragem por locação e a média do valor de
cada locação.
Indicar a locação mais cara e a locação mais barata.
Deve-se fazer duas implementações:
a) Utilizando structs (novo tipo, utilizar typedef), agrupadas em um vetor.
b) Utilizando vetores de strings para armazenar os dados textuais, e uma matriz dinâmica
para armazenar os dados numéricos.
Nome do arquivo: carros.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct loca{
        char nome[50];
        char modelo[15];
        float k_saida;
        float k_chegada;
        float k_total;
        float valor;
        float v_total;
        }loca; 
        
int main() {
    loca *x=NULL;
    int i=0,j=0,m=0,n=0;
    float media[2];
    
        media[0]=0;
        media[1]=0;
        x=(loca*)malloc(sizeof(loca)*1); 
    for(i=0;j!=1;i++){
          
          printf("\n o nome do %d§ cliente\n",i+1);
          gets(x[i].nome);
         if(i>0) gets(x[i].nome);
          
          printf("\n o modelo do carro do cliente %s \n",x[i].nome);
          gets(x[i].modelo);
          
          printf("\n A quantidade de kilometros inicial do cliente %s \n",x[i].nome);
          scanf("%f",&x[i].k_saida);
          
          printf("\n A quantidade de kilometros final do cliente %s \n",x[i].nome);
          scanf("%f",&x[i].k_chegada);
          
          printf("\n o valor a se cobrado por kilometro do cliente %s \n",x[i].nome);
          scanf("%f",&x[i].valor);
          
          
          if (x[i].k_chegada > x[i].k_saida){
             x[i].k_total=x[i].k_chegada-x[i].k_saida;
           }
           else {
                 x[i].k_total=x[i].k_saida-x[i].k_chegada;
                 
             }
          x[i].v_total=x[i].k_total*x[i].valor;

          printf("\n caso naum haja mais um cliente digite 1.");
          printf("\n senaum digete outro valor :");
          scanf("%d",&j);
          if (x[i].v_total < x[n].v_total){
             n=i;
           }
           if (x[i].v_total > x[m].v_total){
              m=i;
            }
            media[0]+=x[i].v_total;
            media[1]+=x[i].k_total;
           if(j!=1) x=(loca*)realloc(x,sizeof(loca*)*(i+1));
          }
          media[0]/=i;
          media[1]/=i;
         printf("\n\n A media de kilometragem e de %f",media[1]);
         printf("\n A media de valor por locação e de %f",media[0]);
         printf("\n A locação mais barata e de %f:",x[n].v_total);
         printf("\n A locação mais cara e de %f:",x[m].v_total);
          free(x);
        printf("\n ");
            system("PAUSE");
            }
