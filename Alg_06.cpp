#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme{
        int id;
        char tit[25],dat[12],produt[25];
        }filme;
void visualizar(filme *locadora, int qt){
     int i;
     printf("\n\n \t Dados informados: \n\n");
     for (i=0;i<qt;i++){
         printf("\t\t\t tit: %s data: %s produtora: %s\n",locadora[i].tit,locadora[i].dat,locadora[i].produt);
     }
}
void ordenar(filme *locadora, int qt){
     int i,j;
     filme troca;
     printf("\n\n \tOrdem Alfabetica: \n\n");
     for (i=0;i<qt;i++){
         for (j=i+1;j<qt;j++){
             if (strcmp(locadora[i].tit,locadora[j].tit)>0){
                troca=locadora[i];
                locadora[i]=locadora[j];
                locadora[j]=troca;
              }
         }
     }
     for (i=0;i<qt;i++){
         printf("\t\t\t %s \n",locadora[i].tit);
     }
}
void buscar(filme *locadora, int qt){
     int i,j,t=0;
     char titulo[45];
     printf("\n\n \tInforme o titulo: \n\n");
     gets(titulo);
     gets(titulo);
     for (i=0;i<qt;i++){
             if (strcmp(titulo,locadora[i].tit)==0)t=1;break;
     }
     if(t==1){printf("Titulo Encontra!!!\n");
                printf("titulo: %s data: %s produtora: %s\n",(locadora[i].tit),locadora[i].dat,locadora[i].produt);
     }else printf("Titulo Nao Encontra!!!\n");
}
int main (){
    int i,t=0,qt=0,op=0;
    filme *locadora=NULL;
     for (t=0;t!=1;){
         printf("\n\n Digite o valor da funcao q deseja realizar:\n");
         printf("(1)Cadastrar:\n");
         printf("(2)Buscar:\n");
         printf("(3)Ordenar:\n");
         printf("(4)vizualizar:");
         scanf("%d",&op);
     if (op==1){
        printf("informe quantos filmes deseja cadastrar: ");
        scanf("%d",&qt);
        locadora =(filme*)malloc(sizeof(filme) * qt);
        for (i=0;i<qt;i++){
            printf("\nInforme o %d§ titulo: ",i+1);
            gets(locadora[i].tit);
            
            if(i==0)gets(locadora[i].tit);
            printf("\nInforme a %d§ data: ",i+1);
            gets(locadora[i].dat);
            printf("\nInforme a %d§ produtora: ",i+1);
            gets(locadora[i].produt);
     }system("cls");
}
     else if(4)visualizar(locadora,qt);
     else if(op==3) ordenar(locadora,qt);
     else if(op==2) buscar(locadora,qt);
         printf("Deseja realizar outra funcao digite 0 senao digite 1:\n");
         scanf("%d",&t);
         system("cls");
     }free(locadora);
     printf("\n\n");
    system("PAUSE");
}
