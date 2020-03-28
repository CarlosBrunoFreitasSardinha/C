#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERI_I 1
#define INSERI_F 2
#define INSERI_P 3

#define DELETA_I 4
#define DELETA_F 5
#define DELETA_P 6
#define DELETA_E 7

#define SAIR 8

typedef struct lista{
        char titulo[45],produtora[45],idioma[20];
        int ano;
        lista*proximo;
}lista;


int vazia (lista**l){
    if((*l)==NULL){
    return 1;
}
    else return 0;
}


void *inserir_v (lista**l, int ano, char *titulo, char *produtora, char *idioma){
      (*l) = (lista*)malloc(sizeof(lista));
      strcpy((*l)->titulo, titulo);
      strcpy((*l)->produtora, produtora);
      strcpy((*l)->idioma, idioma);
      (*l)->ano = ano;
      (*l)->proximo = NULL;
}

///////////////////////////////////////////////////////////////////////////////////


lista *inserir_i (lista**l, int ano, char *titulo, char *produtora, char *idioma){
      
      if(vazia (&(*l)) ){
      inserir_v (&(*l), ano, titulo, produtora, idioma);
      return 0;
}

      lista *aux= *l, *novo;
      
      novo = (lista*)malloc(sizeof(lista));
      strcpy(novo->titulo, titulo);
      strcpy(novo->produtora, produtora);
      strcpy(novo->idioma, idioma);
      novo->ano = ano;
      novo->proximo = aux;
      (*l) = novo;
}

void *inserir_f (lista**l, int ano, char *titulo, char *produtora, char *idioma){
      
      if(vazia (&(*l)) ){
      inserir_v (&(*l), ano, titulo, produtora, idioma);
      return 0;
}

      lista *aux= *l, *novo;
      
      while(aux->proximo!=NULL){
      aux = aux->proximo;
      }
      novo = (lista*)malloc(sizeof(lista));
      strcpy(novo->titulo, titulo);
      strcpy(novo->produtora, produtora);
      strcpy(novo->idioma, idioma);
      novo->ano = ano;
      novo->proximo=NULL;
      aux->proximo=novo;
}



lista *inserir_p (lista **l, int ano, char *titulo, char *produtora, char *idioma, int posicao){
      lista *aux= *l, *novo, *ant;
      int cont=1;
      
      if(vazia (&(*l)) ){
      inserir_v (&(*l), ano, titulo, produtora, idioma);
      return 0;
}

      while (aux!=NULL){
      if(cont==posicao){break;
}
      
      ant = aux;
      aux = aux->proximo;
      cont++;
}

      if(cont!=posicao){
      return 0;
}
      
      novo = (lista*)malloc(sizeof(lista));
      strcpy(novo->titulo, titulo);
      strcpy(novo->produtora, produtora);
      strcpy(novo->idioma, idioma);
      novo->ano = ano;
      novo->proximo = aux;
      
      if(posicao==0){
      (*l)=novo;
}
      
      else{
      ant->proximo=novo;
      
      //return 1;
}
}
      

///////////////////////////////////////////////////////////////////////////////////


      
int *remover_i(lista **l){
      
      lista *aux= *l, *ant;
      
      if(vazia (&(*l)) ){
      return 0;
}
      
      ant = aux;
      free(ant);
      aux = aux->proximo;
      (*l) = aux;
}
      
int *remover_f(lista **l){
    
    lista *aux= *l, *ant;
    
    if(vazia (&(*l)) ){
    return 0;
}

    while (aux->proximo != NULL){
          ant = aux;
          aux = aux->proximo;
}

          ant->proximo = NULL;
          free(aux);
          
          //return 1;
}

int *remover_p(lista **l, int posicao){
    
    lista *aux=*l, *ant;
    int cont=1;
    
    if(vazia (&(*l)) ){
    return 0;
}

    while (aux!= NULL){
    if(cont==posicao){
    break;
}
    
    ant = aux;
    aux = aux->proximo;
    cont++;
}
    
    if(cont!=posicao){
    return 0;
}

    if(posicao==0){
        (*l)=(*l)->proximo;           
    free(aux);
}

    else{
    
    ant->proximo = aux->proximo;
    free(aux);
}

    //return 1;
}



void exibir(lista **l){
     
     lista *aux=*l;
     int i=1;
     
     while   (aux!=NULL){
             printf("%d -- Titulo: %s, Produtora: %s, Idioma: %s, Ano: %d \n", i, aux->titulo, aux->produtora, aux->idioma, aux->ano);
     aux = aux->proximo;
     i++;
}

     printf("\n\n\n");
}


void inserir (lista**l, int ano, char *titulo, char *produtora, char *idioma){
     
     int opcao, posicao;
     
     
     do{
         printf("\t\t\t\n\nDigite: \n\n\n");
         
         printf("\n\n%d -- Inserir no Inicio", INSERI_I);
         printf("\n\n%d -- Inserir no Final", INSERI_F);         
         printf("\n\n%d -- Inserir numa Determinada Posicao", INSERI_P);
         printf("\n\n%d -- Para Sair\n\n", SAIR);
         scanf("%d", &opcao);
         
         switch(opcao){
                       
                       
                       case INSERI_I:
                            inserir_i ((&(*l)), ano, titulo, produtora, idioma);
                            opcao=SAIR;
                       break;
                       
                       case INSERI_F:
                            inserir_f ((&(*l)), ano, titulo, produtora, idioma);
                            opcao=SAIR;
                       break;
                       
                       case INSERI_P:
                            
                            printf("\n\nDigite a Posicao: ");
                            scanf("%d", &posicao);
                                                        
                            inserir_p ((&(*l)), ano, titulo, produtora, idioma, posicao);
                            opcao=SAIR;
                       break;
                       
                       case SAIR:
                       break;
                       
                       default:
                            printf("Opcao invalida");
                       break;

}
}while(opcao!=SAIR);

}


int remover (lista **l){
    
    int posicao, opcao;
    
    do{
        printf("\t\t\t\n\nDigite: \n\n\n");
        
        printf("\n\n%d -- Remover no Inicio", DELETA_I);
        printf("\n\n%d -- Remover no Final", DELETA_F);         
        printf("\n\n%d -- Remover numa Determinada Posicao", DELETA_P);
        printf("\n\n%d -- Remover numa Determinado Elemento", DELETA_E);
        printf("\n\n%d -- Para Sair\n\n", SAIR);
        
        scanf("%d", &opcao);
        
        switch(opcao){
                      case DELETA_I:
                      remover_i(&(*l));
                      opcao=SAIR;
                      break;
                      
                      case DELETA_F:
                      remover_f(&(*l));
                      opcao=SAIR;
                      break;
                      
                      case DELETA_P:
                      
                      printf("Digite a Posicao: ");
                      scanf("%d", &posicao);     
                           
                      remover_p(&(*l), posicao);
                      opcao=SAIR;
                      break;
                      
                      case DELETA_E:    
                      printf("Remover por elemento esta em uma pequena manuten��o\n\n Va se Divertir um poco e tente mais Tarde =)");
                      opcao=SAIR;
                      break;
                      
                      case SAIR:
                           
                      break;
                       
                      default:
                              
                      printf("Opcao invalida");
                      break;
}
}while(opcao!=SAIR);
}
