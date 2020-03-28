/*
3. Implemente um programa em C, utilizando alocação dinâmica com ponteiros de memória,
para contabilizar o total de uma compra. O mesmo deve receber o código de cada item, a
quantidade e o preço. Então deverá calcular e imprimir o subtotal para cada item, o total
da compra, o item mais caro e o mais barato. O algoritmo deve conter, pelo menos, 3
funções e deve-se utilizar passagem de parâmetro por referência. Observe o exemplo a
seguir:
       
Item Código Quantidade Preço    Subtotal
1    11111  10         150,00   1.500,00
2    22222  5          100,00   500,00
3    33333  20         10,00    200,00
4    44444  2          200,00   400,00

Total: 2600
Mais caro: 11111
Mais barato: 33333

Deve-se fazer duas implementações:
        
a) Utilizando structs (novo tipo, utilizar typedef), agrupadas em um vetor.
b) Utilizando vetores de strings para armazenar os dados textuais, e uma matriz dinâmica
para armazenar os dados numéricos.
Nome do arquivo: compras.c*/

#include <stdio.h>
#include <stdlib.h>


  float total(int lin,float **m){
        int i;
        float z=0;
        for (i=0;i<lin;i++){
             z+=m[i][2];
         }
         return(z);
   }
   
   void le(int *lin){
   
     printf("\n Quantos produtos ira calcular: ");
     scanf("%d",lin);
   }
   
int main(){
    system("color f2");
    int i,col=4,lin=1;
    float **m=NULL;
    
    int j=0;
    le(&lin);
     m=(float**)malloc(sizeof(float*)*(lin));
     
       for (i=0;i<lin;i++){
           m[i]=(float*)malloc(sizeof(float*)*col);
           printf("\n Digite o codigo: ");
           scanf("%f",&m[i][3]);
           printf("\n Digite a quantidade: ");
           scanf("%f",&m[i][1]);
           printf("\n Digite o seu presso: ");
           scanf("%f",&m[i][0]);
           m[i][2]=m[i][1]*m[i][0];
           }
           int k;
        float z;
        for (i=0;i<lin;i++){
            if (i==0||z<m[i][2]){
               z=m[i][2];
               k=i;
             }
         }
    system("cls");
   printf("\n\n\n\t\t codigo| presso| quantidade| subtotal|");
   
    for (i=0;i<lin;i++){
        printf("\n\t\t sd %.0f |    %.2f|   %.0f   |   %.2f",m[i][3],m[i][0],m[i][1],m[i][2]);
        }
    printf("\n\n\n\t\t\t\t o + caro: %.0f por %.2f",m[k][3],m[k][2]);
    for (i=0;i<lin;i++){
            if (i==0||z>m[i][2]){
               z=m[i][2];
               k=i;
             }
         }
    printf("\n\t\t\t\t o + barato: %.0f por %.2f",m[k][3],m[k][2]);
    z=0;
        for (i=0;i<lin;i++){
             z+=m[i][2];
         }printf("\n\t\t\t\t O total eh: %.2f\n\n",total(lin,m));/* */
    free(m);
    system("PAUSE");
    return(1);
}

