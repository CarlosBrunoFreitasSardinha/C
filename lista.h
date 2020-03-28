#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERT_END 1
#define INSERT_START 2
#define INSERT_POSITION 3
#define INSERT_ELEMENT 4


#define DELET_POSITION 5
#define DELET_END 6
#define DELET_START 7
#define DELET_ELEMENT 8
#define SAIR 9

typedef struct lista{
       int ano;
       lista *proximo; 
       char produtora[45], idioma[45], titulo[45];
}lista;
//------------------------------------------------------------------------------
int vazia(lista **l){
     if((*l) == NULL)return 1;
     else return 0;
     }
//------------------------------------------------------------------------------
void insert_vazia(lista **l,char *titulo,char *produtora,char *idioma,int ano){
     (*l) = (lista*)malloc(sizeof(lista));
     strcpy((*l)-> titulo, titulo);
     strcpy((*l)-> produtora, produtora);
     strcpy((*l)-> idioma, idioma);
     (*l)->ano= ano;
     (*l)->proximo=NULL;
     
           printf("\n O %s e de : %d",(*l)->titulo,(*l)->ano);
           system("pause"); 
 }
//------------------------------------------------------------------------------
int insert_position(lista **l, int posicao,char *titulo,char *produtora,char *idioma,int ano){
    lista *aux=*l , *ant, *novo;
    int count=0;
    
    if (vazia(&(*l))){
       insert_vazia(&(*l),titulo,produtora,idioma,ano);
       return (0);
    }
    
    while (aux != NULL){
          if (count==posicao)break;
             ant = aux;
             aux = aux->proximo;
             count++;}
      if (count!=posicao)return (0);
         novo = (lista*)malloc(sizeof(lista));
         strcpy(novo-> titulo, titulo);
         strcpy(novo-> produtora, produtora);
         strcpy(novo-> idioma, idioma);
         novo->ano= ano;
         novo->proximo=aux;
     if (posicao==0)(*l)=novo;
     else ant->proximo=novo;
    return 1;
    }
//------------------------------------------------------------------------------
int insert_inicio(lista **l,char *titulo,char *produtora,char *idioma,int ano){
     
    if (vazia(&(*l))){
       insert_vazia(&(*l),titulo,produtora,idioma,ano);
       return (0);
    }
     
    lista *aux=*l, *novo;
    
         novo = (lista*)malloc(sizeof(lista));
         strcpy(novo-> titulo, titulo);
         strcpy(novo-> produtora, produtora);
         strcpy(novo-> idioma, idioma);
         novo->ano= ano;
         novo->proximo=aux;
         *l=novo;
}
//------------------------------------------------------------------------------
int insert_fim(lista **l,char *titulo,char *produtora,char *idioma,int ano){
     
    if (vazia(&(*l))){
       insert_vazia(&(*l),titulo,produtora,idioma,ano);
       return (0);
    }
     
    lista *aux=*l, *novo;
    system("pause");
    while (aux->proximo != NULL){aux = aux->proximo;}
    system("pause");
         novo = (lista*)malloc(sizeof(lista));
         strcpy(novo-> titulo, titulo);
         strcpy(novo-> produtora, produtora);
         strcpy(novo-> idioma, idioma);
         novo->ano= ano;
         novo->proximo=NULL;
         aux->proximo=novo;
         return 1;
}
//--------------------------------remover---------------------------------------
int delet_position(lista **l, int posicao){
    lista *aux=*l , *ant;
    int count=1;
    
    if (vazia(&(*l)))return (0);
    
    while (aux != NULL){
          if (count==posicao)break;
             ant = aux;
             aux = aux->proximo;
             count++;
             }
          if (count!=posicao)return (0);
          else if (posicao==0){
               (*l)=aux->proximo;
               free(aux);
               }
          else {
               ant->proximo=aux->proximo;
               free(aux);
               }
    return 1;
}
//--------------------------------remover---------------------------------------
int delet_element(lista **l, int element){
    lista *aux=(*l) , *ant;
    int count=0;
    
    if (vazia(&(*l)))return (0);
    while (aux != NULL){
          if (aux->ano==element){
             if (count==0){
                (*l)=aux->proximo;
                free(aux);
                aux=(*l);
              }
              else if(aux->proximo==NULL){
                   
                   }
              else {
                  ant->proximo=aux->proximo;
                  free(aux);
                  aux=ant->proximo;
               }
           }if(aux->proximo==NULL||aux==NULL)break;
           ant = aux;
           aux = aux->proximo;
           count++;
    }
    return 1;
}
//-----------------------------------------------------------------------------
int delet_inicio(lista **l){
    lista *aux=*l, *ant;
    if (vazia(&(*l)))return (0);
        ant= aux;
        aux = aux->proximo;
       (*l)=aux;
}
//------------------------------------------------------------------------------
int delect_fim(lista **l){
    lista *aux=*l, *ant;
    if (vazia(&(*l)))return (0);
    
    while (aux->proximo != NULL){
          ant=aux;
          aux = aux->proximo;
    }
          ant->proximo=NULL;
          free(aux);
          return 1;
}
//------------------------------exibir------------------------------------------
void listar(lista **l){
     lista *aux=*l;
     int i=0;
     while (aux!=NULL){
           printf("\n O %s e de : %d",aux->titulo,aux->ano);
           aux=aux->proximo;
           i++;
     }
     printf("\n\n\n");
}
//---------------------------função mestre Remover------------------------------
int remover(lista **l){
     system("cls");
     int op,posicao,element;
     do{
       printf("\n\n%d - Remover no Fim;\n",DELET_END);
       printf("%d - Remover no Inicio;\n",DELET_START);
       printf("%d - Remover na Posicao x;\n",DELET_POSITION);
       printf("%d - Remover Elemento(ano);\n",DELET_ELEMENT);
       printf("%d - Cancelar;\n",SAIR);
       printf("informe a opcao: ");
       scanf("%d",&op);
       switch (op){
              case DELET_POSITION:
                   printf("\n\ninforme a posicao: ");
                   scanf("%d",&posicao);
                   delet_position(&(*l), posicao);
                   op=SAIR;
              break;
              case DELET_END:
                   delect_fim(&(*l));
                   op=SAIR;
              break;
              case DELET_START:
                   delet_inicio(&(*l));
                   op=SAIR;
              break;
              case DELET_ELEMENT:
                   printf("\n\nInforme o valor do elemento(ano): ");
                   scanf("%d",&element);
                   delet_element(&(*l),element);
                   op=SAIR;
              break;
              case SAIR: 
              break;
              default:
                printf ("\n\nERRO: Opcao Invalida.");
              break;
        }
     }while(op!=SAIR);
}
//---------------------------função mestre Inserir------------------------------
void inserir(lista **l,int ano, char *titulo, char *idioma, char *produtora){
     system("cls");
     int op,posicao;
     do{
       printf("\n\n%d - Inserir no Fim;\n",INSERT_END);
       printf("%d - Inserir no Inicio;\n",INSERT_START);
       printf("%d - Inserir na Posicao x;\n",INSERT_POSITION);
       printf("%d - Inserir Ordenadamente;\n",INSERT_ELEMENT);
       printf("%d - Cancelar;\n",SAIR);
       printf("informe a opcao: ");
       scanf("%d",&op);
       switch (op){
              case INSERT_POSITION:
                   printf("\n\ninforme a posicao: ");
                   scanf("%d",&posicao);
                   insert_position(&(*l),posicao,titulo,produtora,idioma,ano);
                   op=SAIR;
              break;
              case INSERT_END:
                   insert_fim(&(*l),titulo,produtora,idioma,ano);
                   op=SAIR;
              break;
              case INSERT_START:
                   insert_inicio(&(*l),titulo,produtora,idioma,ano);
                   op=SAIR;
              break;
              case INSERT_ELEMENT:
                   
              break;
              case SAIR: 
              break;
              default:
                printf ("\n\nERRO: Opcao Invalida.");
              break;
        }
     }while(op!=SAIR);
}
